#include <cstdint>
#include <fstream>
#include <iostream>
#include <chrono>
#include <random>
#include <cstring>

class Chip8{
    const unsigned int START_ADDRESS = 512 ;// start index is 0x200
    const unsigned int FONTSET_SIZE = 80 ,FONTSET_START_ADDRESS = 80  ; //  representaition of characters from 1-F will take 5 lines each of 8 bits

    uint8_t registers[16] ,memory[4096]{} , stackPointer{} , delayTimer ,soundTimer ,keypad[16] ;
    uint16_t index , programCounter , stack[16] ,opcode ;
    uint32_t video[64][32] ;
    std::default_random_engine randGen ;
    std::uniform_int_distribution<uint8_t> randByte ;


public:
    Chip8() : randGen(std::chrono::system_clock::now().time_since_epoch().count()){
        programCounter = START_ADDRESS ;

        uint8_t fontset[] =
                {
                        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
                        0x20, 0x60, 0x20, 0x20, 0x70, // 1
                        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
                        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
                        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
                        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
                        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
                        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
                        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
                        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
                        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
                        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
                        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
                        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
                        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
                        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
                };
        for(int i= 0 ;i<FONTSET_SIZE ;i++){
            memory[FONTSET_START_ADDRESS +i] = fontset[i] ;
        }

        randByte =std::uniform_int_distribution<uint8_t>(0,255U) ; // this will give us a random byte from 0..255
    }

    void LoadRom(const char* filename){
        std::ifstream file(filename , std::ios::binary | std::ios::ate) ;
        if(file.is_open()){
            std::streampos size = file.tellg() ;
            char* buffer = new char[size] ;

            file.seekg(0,std::ios::beg) ;
            file.read(buffer,size) ;
            file.close() ;
            std::cerr<<"file opened , size is "<<size<<"\n" ;
            for(long long i = 0 ; i<size ;i++){
                memory[START_ADDRESS +i] = buffer[i] ;
                std::cerr<<buffer<<"\n" ;
            }

            delete[] buffer ;
            std::cerr<<"loading complete"<<std::endl ;
        }
    };

    void OP_00E0(){
        memset(video,0 ,sizeof(video)) ;
    }

    void OP_OOEE(){
        --stackPointer ;
        programCounter =stack[stackPointer] ;
    }

    void OP_1nnn(){
        uint16_t address = opcode & 0x0FFFu ;
        programCounter = address ;
    }

    void OP_2nnn(){
        stack[stackPointer]= programCounter ;
        ++stackPointer;
        uint16_t address = opcode & 0x0FFFu ;
        programCounter =address ;
    }

    void OP_3xkk(){
        uint8_t Vx = (opcode & 0x0F00u) >>8u ;
        uint8_t byte = opcode & 0x00FFu ;

        if(registers[Vx]==byte) {
            programCounter += 2;
        }
    }

    void OP_4xkk(){
        uint8_t Vx = (opcode & 0x0F00u) >> 8u ;
        uint8_t byte = opcode & 0x00FFu ;

        if(registers[Vx] != byte){
            programCounter +=2 ;
        }
    }

    void OP_5xy0(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;
        if(registers[Vx] == registers[Vy]){
            programCounter +=2 ;
        }
    }

    void OP_6xkk(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t val = (opcode & 0x00FFu ) ;
        registers[Vx] =val ;
    }

    void OP_7xkk(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t val = (opcode & 0x00FFu ) ;
        registers[Vx] += val ;
    }

    void OP_8xy0(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;
        registers[Vx]=Vy ;
    }

    void OP_8xy1(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;
        registers[Vx] |=Vy ;
    }

    void OP_8xy3(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;
        registers[Vx] &=Vy ;
    }

    void OP_8xy4(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;

        uint16_t sum  = registers[Vx] + registers[Vy] ;
        if(sum > 255u){
            registers[0xF] = 1 ;
        }
        else{
            registers[0xF] = 0;
        }
        registers[Vx] = sum & 0xFFu ;
    }

    void OP_8xy5(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;

        if(Vx > Vy){
            registers[0xF] = 1 ;
        }
        else{
            registers[0xF] = 0;
        }
        registers[Vx] -= registers[Vy] ;
    }

    void OP_8xy6(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;


        registers[0xF] = registers[Vx]  & 0x1u ;

        registers[Vx] >>=  1;
    }

    void OP_8xy7(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;

        if(Vx  < Vy){
            registers[0xF] = 1 ;
        }
        else{
            registers[0xF] = 0;
        }
        registers[Vx] = registers[Vy]-  registers[Vx] ;
    }

    void OP_8xyE(){
        uint8_t Vx = (opcode & 0x0F00u) >> 8u;
        registers[0xF] = (registers[Vx] & 0x80u) >> 7u;

        registers[Vx] <<= 1;
    }

    void OP_9xy0(){
        uint8_t Vx = (opcode & 0x0F00u ) >> 8u ;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u ;
        if(registers[Vx] != registers[Vy]){
            programCounter +=2 ;
        }
    }

    void OP_Annn(){
        uint16_t address = opcode & 0x0FFFu;

        index = address;
    }

    void OP_Bnnn(){
        uint16_t address = opcode & 0x0FFFu;

        programCounter = address +registers[0];
    }

    void OP_Cxkk(){
        uint8_t Vx = (opcode & 0x0F00u) >> 8u;
        uint8_t byte = opcode & 0x00FFu;

        registers[Vx] = randByte(randGen) & byte;
    }

    void OP_Dxyn() {
        uint8_t Vx = (opcode & 0x0F00u) >> 8u;
        uint8_t Vy = (opcode & 0x00F0u) >> 4u;
        uint8_t height = opcode & 0x000Fu;

        uint8_t xpos = registers[Vx] % 64 ;
        uint8_t ypos = registers[Vy] % 32 ;

        registers[0xF] =0 ;

        for(int row=0 ; row < height ;row++){
            uint8_t spritebyte = memory[index+row] ;
            for(int col =0 ; col < 8; col++){

            }
        }
    }












};


int main() {

    return 0;
}
