#include<stdio.h>
#include<stdlib.h>
struct location{
	int x,y;
	int sim;
};
void dnaCreator(int DNA[50][50]);
struct location dnaFind(int DNA[50][50],int desDNA[10],int desSim);
int main(){
	int DNA [50][50];
	struct location loc;
	int i =0,j=0;
	dnaCreator(DNA);
	int desDNA[]={1,1,1,3,1,3,3,1,1,0};
	loc= dnaFind(DNA,desDNA,100);
	
	printf("**************************** DNA  HARITASI ************************************************\n");
	for(;i<50;i++){
		for(j=0;j<50;j++){
	
			printf("%d ",DNA[i][j]);
		}
		puts("\n");
	}	
	printf("*********************************************************************************************\n");
	
	printf("\n**************************** Sonuclar *********************************************************\n");
	if(loc.x != -1){
		loc.sim=0;
		printf("Eslesen parca : ");
		j=0;
		for(i=loc.y;i<loc.y+10;i++){
			printf("%d ",DNA[loc.x][i]);
			if(DNA[loc.x][i]==desDNA[j])
				loc.sim+=10;
			j++;
		}	
	
		printf("\n%d th line has the similarity in the locaions between %d - %d and the similarity %d percent\n",loc.x+1,loc.y+1,loc.y+11,loc.sim);
	}
	else{
		printf("Benzerlik bulunamadi !!!\n");
	}
	
	printf("*********************************************************************************************");

	return 0; 
}


void dnaCreator(int DNA[50][50]){
	int i=0,j=0;
	for(;i<50;i++){
		for(j=0;j<50;j++){
			DNA[i][j]=rand()%4;			
		}
	}
	
}

struct location dnaFind(int DNA[50][50],int desDNA[10],int desSim){
	struct location loc;
	int i ,j,k=0,l=0;
	
	int sim =100;
	int finded =0;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			
			if(DNA[i][j]!=desDNA[k]){
				
				l++;
				j=l;
				k=0;
				sim=0;
			//	printf("%d %d \n",DNA[i][j],desDNA[k]);
			}
			else{
				sim+=10;
				if(k==9 || desSim ==sim){
				loc.y=j-k;
				loc.x=i;
				loc.sim=sim;
				finded=1;
				break;
			}
			else{
				k++;
			}
				
			}
		}
	}
	if ( desSim <40){
		loc.x=-1;
		loc.y=-1;
		return loc;
	}
	if(finded == 0)
		loc =dnaFind(DNA,desDNA,desSim-10);
	
	return loc;	
}
