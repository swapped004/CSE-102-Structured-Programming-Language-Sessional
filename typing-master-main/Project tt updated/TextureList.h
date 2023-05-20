#include "texture.h"

texture textures[20];

//texture textureVariable;

void textureInit()
{
    textures[0].Create("front.bmp");
	textures[1].Create("pp2.bmp");
    textures[2].Create("ss5.bmp");
    textures[3].Create("ins.bmp");
    textures[4].Create("emo.bmp");
    textures[5].Create("ss8.bmp");
    textures[6].Create("loop1.bmp");
    textures[7].Create("image_2.bmp");
    textures[8].Create("see.bmp");
    textures[9].Create("credit subs.bmp");//credit1.bmp"
    textures[10].Create("credit2.bmp");
    textures[11].Create("over.bmp");
    textures[12].Create("high.bmp");
    textures[13].Create("back.bmp");
    textures[14].Create("mode15.bmp");
    textures[15].Create("winner1.bmp");
    textures[16].Create("game_loser.bmp");
    textures[17].Create("timesup.bmp");
    textures[18].Create("options.bmp");








	//textureVariable.Create("google.bmp");
}



/**
How to use texture image:

1. in TextureList.h: declare texture type variables as needed. For every image, you need to declare one texture type variable.

Example:

texture textureVariable;


2. in TextureList.h: in the function textureInit(): initialize the texture variable that you declared in step 1 with the name
of the image file.

Example: suppose you have an image file named: "google.bmp"
then, you initialize as follows:

textureVariable.Create("google.bmp");


3. in the main cpp file in iDraw function: use drawTexture function to draw the image. drawTexture takes three arguments.

-> first argument   : lower left x-coordinate of the image
-> second argument  : lower left y-coordinate of the image
-> third argument   : name of the textureVariable declared in step 1


Example:

drawTexture(100, 200, textureVariable);
**/
