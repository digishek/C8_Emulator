C8_Emulator                                                                                                                                                                                                      
===========                                                                                                                                                                                        
[![System Structure Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)

	      #@@@@@@@@@@@.                                  @@@@@@@@@@@@@@@@,                                          @@@@@%                  @@@@@#                                          
	    @@@@@@@@@@@@@@.    @@@@@@@@@                     @@@@@@@@@@@@@@@@,                                          @@@@@%                  @@@@@#                                          
	  %@@@@@@%        .  @@@@@@@@@@@@@@                  @@@@@@                                                     @@@@@%                  @@@@@#                                          
	  @@@@@@            @@@@@.    @@@@@*                 @@@@@@          @@@@@*@@@@@@@@/@@@@@@@@@. @@@@@@     #@@@@@@@@@@%@@@@@@@@@@@&   @@@@@@@@@@@@@    &@@@@@@@@@   ,@@@@@@@@@@@@        
	 @@@@@@             @@@@@&    @@@@@                  @@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     #@@@@@@@@@@%@@@@@@@@@@@@@@ @@@@@@@@@@@@@  @@@@@@@@@@@@@@.,@@@@@@@@@@@@        
	 @@@@@@              @@@@@@@@@@@@@                   @@@@@@@@@@@@@@@ @@@@@@    @@@@@@/   ,@@@@@@@@@@@     #@@@@@@@@@@%@&       @@@@@@   @@@@@#     @@@@@@    @@@@@@(@@@@@@@             
	 @@@@@@             @@@@@@@@@@@@@@@                  @@@@@@@@@@@@@@@ @@@@@(    %@@@@@     @@@@@@@@@@@     #@@@@@@@@@@% @@@@@@@@@@@@@@   @@@@@#    @@@@@@      @@@@@@@@@@@/              
	 ,@@@@@#           @@@@@@,    @@@@@@                 @@@@@@          @@@@@(    %@@@@@     @@@@@@@@@@@     #@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@#    @@@@@@      @@@@@@@@@@@*              
	  @@@@@@@          @@@@@(      @@@@@(                @@@@@@          @@@@@(    %@@@@@     @@@@@@@@@@@     @@@@@@@@@@@@@@@@.    %@@@@@   @@@@@&    ,@@@@@(     @@@@@@@@@@@*              
	   (@@@@@@@@@@@@@@@#@@@@@@@&@@@@@@@@(                @@@@@@@@@@@@@@@@@@@@@(    %@@@@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@&@@@@@@@@@@@@@@@,@@@@@*              
	     *@@@@@@@@@@@@@  @@@@@@@@@@@@@@(                 @@@@@@@@@@@@@@@@@@@@@(    %@@@@@     @@@@@&*@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@     @@@@@@@@@  @@@@@@@@@@@@  ,@@@@@*              
					    @@@@@@@@@@@@@@@@@                                                                                                                                   
					    @@@@@@@@@@@@@@@@@      

The free and open-source Chip 8 emulator/debugger, written in C++ for Windows and Linux.

## Working 

I have used implemented a simple Chip 8 interpreted using C++ , and am using STD2 for rendering the 64x32 pixels . 
The Chip8 class read's the instrucitons from .ch8 files, interpretes all the CPU commands , and executes them .
The platform class displays the changes in the (64x32 display grid) .

For a more detailed explanation please refer [![here](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)](https://austinmorlan.com/posts/chip8_emulator/).

I have tested tetris and space invaders , both are playable. 



![tetris](https://user-images.githubusercontent.com/45209646/140600492-ded30cca-deed-47ec-a0d7-ea4bee6de079.gif)



![space_invaders](https://user-images.githubusercontent.com/45209646/140600171-dfaccd47-bb78-4154-8834-38b6d84600ab.gif)







## Usage 

You can either directly import this projects from Clion , or run it chip8 file in the debug folder . 
The main files expects some arguments in the following format :

	$./chip8 scale delay filename

Scale - Multiplier for display scaling since 64x32 is too small for modern devices (10-20 recommended) 

Delay - Delay for inbuilt timers . This values dependes on the game(1-10 Recommended) 

Filename - Name of the .ch8 file you want to run .


You can check out some games [![here](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)](https://github.com/JohnEarnest/chip8Archive/tree/master/roms).





## License

Meh , Use it however you want .



						    
				

                                                                                                                                                                 
                                                                                                                                                                 
