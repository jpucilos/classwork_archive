/**********************************************************************************
* imageproc.c
* Usage: imageproc in_file_name out_file_name width height
 **********************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "CImg.h"
using namespace cimg_library;

int main(int argc, char *argv[])
{
	FILE  *in, *out;
	int   j, k, width, height;
	int ** image_in, ** image_out;
	float sum1, sum2;
	float new_T, old_T, delta_T;
	long count1, count2;



	if(argc<5) { printf("ERROR: Insufficient parameters!\n"); return(1);}

	width = atoi(argv[3]);
	height = atoi(argv[4]);

	image_in = (int**) calloc(height, sizeof(int*));
	if(!image_in)
	{
		printf("Error: Can't allocate memmory!\n");
		return(1);
	}

	image_out = (int**) calloc(height, sizeof(int*));
	if(!image_out)
	{
		printf("Error: Can't allocate memmory!\n");
		return(1);
	}

	for (j=0; j<height; j++)
	{
		image_in[j] = (int *) calloc(width, sizeof(int));
		if(!image_in[j])
		{
			printf("Error: Can't allocate memmory!\n");
			return(1);
		}

		image_out[j] = (int *) calloc(width, sizeof(int));
		if(!image_out[j])
		{
			printf("Error: Can't allocate memmory!\n");
			return(1);
		}

	}

	if((in=fopen(argv[1],"rb"))==NULL)
	{
		printf("ERROR: Can't open in_file!\n");
		return(1);
	}

	if((out=fopen(argv[2],"wb"))==NULL)
	{
		printf("ERROR: Can't open out_file!\n");
		return(1);
	}

	for (j=0; j<height; j++)
		for (k=0; k<width; k++)
	    	{
			if((image_in[j][k]=getc(in))==EOF)
			{
				printf("ERROR: Can't read from in_file!\n");
				return(1);
		      }
	    	}
      if(fclose(in)==EOF)
	{
		printf("ERROR: Can't close in_file!\n");
		return(1);
	}

	/* display image_in */
	CImg<int> image_disp(width, height,1,1,0);
	/* CImg<type> image_name(width,height,temporal_frame_number,color_plane_number,initial_value) */

	for (j=0; j<height; j++)
		for (k=0; k<width; k++)
	   	{
			image_disp(k,j,0,0) = image_in[j][k];
		}
	CImgDisplay disp_in(image_disp,"Image_In",0);
	/* CImgDisplay display_name(image_displayed, "window title", normalization_factor) */


/********************************************************************/
/* Image Processing begins                                          */
/********************************************************************/
	/*
	for (j = 0; j < height; j++){
		for (k = 0; k < width; k++){
			image_out[j][k]=255-image_in[j][k];
		}
	}
	*/


	/*
		//Part 2 - Histogram Equalization
	int histo[256];
	for (int i = 0; i < 256; i++)
		histo[i] = 0;

	for (j = 0; j < height; j++){
		for (k = 0; k < width; k++){
			histo[image_in[j][k]]++;
		}
	}
	int cumulative_hist[256];
	cumulative_hist[0] = histo[0];
	for (int i = 1; i < 256; i++){
		cumulative_hist[i] = histo[i] + cumulative_hist[i - 1];
	}
	
	int scaled_hist[256];
	for (int i = 0; i < 256; i++){
		scaled_hist[i] = floor((double)255 / (height*width) * cumulative_hist[i] + 0.5);
	}
	for (j = 0; j < height; j++){
		for (k = 0; k < width; k++){
			image_out[j][k] = scaled_hist[image_in[j][k]];
		}
	}
	*/

	/*
	for (j = 0; j < height; j++){
		for (k = 0; k < width; k++){
			float mask[3][3] = { { 0.0, -1.0, 0.0 }, { -1.0, 5.0, -1.0 }, { 0.0, -1.0, 0.0 } };
			float value_out;
			float SUM = 0;


			if (k == width - 1 || k == 0 || j == 0 || j == height - 1)
				image_out[j][k] = image_in[j][k];

			else{
				for (int x = 0; x < 3; x++){
					for (int y = 0; y < 3;y++){
						SUM += ((float)image_in[j + x - 1][k + y - 1] * mask[x][y]);
					}
				}
			}
			value_out = SUM / 9.0;
			value_out = (value_out > 255 ? 255 : value_out);
			value_out = (value_out < 0 ? 0 : value_out);
			image_out[j][k] = (int)value_out;
		}
	}
	*/

	//Homework 7.3
	new_T = 175.0;
	delta_T = 100.0;

	while (delta_T < -5.0 || delta_T > 5.0){

		count1 = 0; 
		count2 = 0;
		sum1 = 0.0; 
		sum2 = 0.0;

		for (j = 0; j < height; j++)
			for (k = 0; k < width; k++){
				if (image_in[j][k] >= new_T){
					count1++;
					sum1 += image_in[j][k];
				}	
				else{
					count2++;
					sum2 += image_in[j][k];
				}
		}
		old_T = new_T;
		new_T = ((sum1 / count1) + (sum2 / count2)) / 2;
		delta_T = new_T - old_T;
		printf("new threshold = %f \n", new_T);
	}
	//thresholding occurs here
	for (j = 0; j < height; j++)
		for (k = 0; k < width; k++)
			image_out[j][k] = (image_in[j][k] >= new_T ? 255 : 0);


/********************************************************************/
/* Image Processing ends                                          */
/********************************************************************/

	/* display image_out */
	for (j=0; j<height; j++)
		for (k=0; k<width; k++)
	   	{
			image_disp(k,j,0,0) = image_out[j][k];
		}
	CImgDisplay disp_out(image_disp,"Image_Out",0);


	/* save image_out into out_file in RAW format */
	for (j=0; j<height; j++)
		for (k=0; k<width; k++)
	    {
	            if((putc(image_out[j][k],out))==EOF)
	            {
		        	printf("ERROR: Can't write to out_file!\n");
				    return(1);
	            }
		}

    if(fclose(out)==EOF)
	{
		printf("ERROR: Can't close out_file!\n");
		return(1);
	}

	/* closing */
	while (!disp_in.is_closed)
		disp_in.wait();
	while (!disp_out.is_closed)
		disp_out.wait();

	for (j=0; j<height; j++)
	{
		free(image_in[j]);
		free(image_out[j]);
	}
	free(image_in);
	free(image_out);

    return 0;
}



