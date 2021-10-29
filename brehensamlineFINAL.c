#include<stdio.h>
#include<time.h>
#include<math.h>
#include <unistd.h>
//color codes
#define RED  "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"
//matrix size
#define size 100
// I used delay because I could not measure time without slowing down the code
#define delay 1000
#define div 4
//measure time *count* times and find average time
#define count 10
void brehensamline(int x1,int y1,int x2,int y2,int a[][size],int dim_x,int dim_y);
void graphic(int x1,int y1,int x2,int y2,int board[][size],int dim_x,int dim_y);
//print a matrix that represents pixels
// RED: start coordinates
// GREEN: end coordianates
void screen(int a[][size],int dim_x,int dim_y,int start_x,int start_y,int end_x,int end_y);


//Omer Sinan Bilget 19011067 12.06.2020
int main(){
	system("cls");
	static int board[size][size];	
	//board size
	int dim_x=20;
	int dim_y=20;
	
	//example values for matrix
	int x1=2;
	int y1=1;
	int x2=14;
	int y2=18;
	printf("example line");
	printf(RED"(%d,%d)"RESET,x1,y1);
	printf("-");
	printf(GREEN"(%d,%d)\n"RESET,x2,y2);
    //show lines in a matrix
    brehensamline(x1,y1,x2,y2,board,dim_x,dim_y);
    screen(board,dim_x,dim_y,x1,y1,x2,y2);
    dim_x=50;
    dim_y=50;
    printf("Length  |Time   |Graph\n");
    printf("---------------------------------------\n");
	//sets for time measure
	// I used 3-4-5 triangle for length
	//start_x start_y end_x end_y
	//                          //length of line  5                   
	int sx1=24;
	int sy1=2;
	int ex1=27;
	int ey1=6;
	graphic(sx1,sy1,ex1,ey1,board,dim_x,dim_y);
    //                          //length of line  10                  
	int sx2=1;
	int sy2=40;
	int ex2=7;
	int ey2=32;
	graphic(sx2,sy2,ex2,ey2,board,dim_x,dim_y);
    //                          //length of line  15                 
	int sx3=1;
	int sy3=2;
	int ex3=10;
	int ey3=14;
    graphic(sx3,sy3,ex3,ey3,board,dim_x,dim_y);
	//                          //length of line  20                 
	int sx4=30;
	int sy4=8;
	int ex4=42;
	int ey4=24;
	graphic(sx4,sy4,ex4,ey4,board,dim_x,dim_y);
    //                          //length of line  25                
	int sx5=25;
	int sy5=40;
	int ex5=40;
	int ey5=20;
	graphic(sx5,sy5,ex5,ey5,board,dim_x,dim_y);
    //                          //length of line  30                
	int sx6=48;
	int sy6=17;
	int ex6=30;
	int ey6=41;
    graphic(sx6,sy6,ex6,ey6,board,dim_x,dim_y);
	//                          //length of line  35                
	int sx7=28;
	int sy7=2;
	int ex7=7;
	int ey7=30;
	graphic(sx7,sy7,ex7,ey7,board,dim_x,dim_y);
    //                          //length of line  40                
	int sx8=36;
	int sy8=40;
	int ex8=12;
	int ey8=8;
	graphic(sx8,sy8,ex8,ey8,board,dim_x,dim_y);
    //                          //length of line  45                
	int sx9=35;
	int sy9=44;
	int ex9=8;
	int ey9=8;
    graphic(sx9,sy9,ex9,ey9,board,dim_x,dim_y);
	//                          //length of line  50               
	int sx10=17;
	int sy10=42;
	int ex10=47;
	int ey10=2;
    graphic(sx10,sy10,ex10,ey10,board,dim_x,dim_y);
    printf("complexity o(n)\n");
    
    return 0;
}
// error used as pk
void brehensamline(int x1,int y1,int x2,int y2,int a[][size],int dim_x,int dim_y){
	// delta x and delta y
	int dx=x2-x1;
	int dy=y2-y1;

    // loop variables
	int i,j;
	// drawing line variable initialized as start coordinates
	int x=x1;
	int y=y1;
	// signs of delta x and delta y
	int signx=1,signy=1;
	if(dx<0){
		signx=-1;
	}
	if(dy<0){
		signy=-1;
	}
	i=0;
	if(abs(dx)>abs(dy)){
	    int error = (abs(dy)<< 1) - abs(dx);
        while(i<abs(dx) && x>=0 && x<dim_x && y>=0 && y<dim_y){
            x+=signx;
            if(error < 0){
                error = error + (abs(dy) << 1);
			}else {
                if(dy!=0){
                	y+=signy;
				}
                error = error + (abs(dy) << 1) - (abs(dx) << 1);
            }
			i+=1;
			usleep(delay);
			
			a[x][y]=1;
        }
    }else{
        int error = (abs(dx) << 1) - abs(dy);
        while(i<abs(dy) && x>=0 && x<dim_x && y>=0 && y<dim_y){
            y+=signy;
            if(error < 0){
                error = error + (abs(dx) << 1);
            }else{
                if(dx!=0){
                	x+=signx;
				}
                error = error + (abs(dx) << 1) - (abs(dy) << 1);
            }  
			i+=1;
			usleep(delay);
			
			a[x][y]=1;
        } 
    }
}

void screen(int a[][size],int dim_x,int dim_y,int start_x,int start_y,int end_x,int end_y){
	int i,j;
	//RED
	a[start_x][start_y]=2;
	//GREEN
	a[end_x][end_y]=3;
	for(i=0;i<dim_x;i++){
		for(j=0;j<dim_y;j++){
			if(a[i][j]==0){
				printf(". ");
			}else if(a[i][j]==1){
				printf("[]");
			}else if(a[i][j]==2){
				printf(RED"[]"RESET);
			}else{
				printf(GREEN"[]"RESET);
			}
		}
		printf("\n");
	}
}

void graphic(int x1,int y1,int x2,int y2,int board[][size],int dim_x,int dim_y){
	int average=0;
	int i;
	for(i=1;i<=count;i++){
		//time measure
        clock_t start,end;
        start = clock();
	    brehensamline(x1,y1,x2,y2,board,dim_x,dim_y);
        end = clock();
        int elapsed=end-start;
        average+=elapsed;
	}
	//measure time *count* times and find average time
	average=average/count;
	
	//find length of line
	int length=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
	printf("%d   \t|%dms\t|",length,average);
	for(i=0;i<average/div;i++){
		printf("/");
	}
	printf("\n");
}
