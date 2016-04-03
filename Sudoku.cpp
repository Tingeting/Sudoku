/*sudoku.cpp*/
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;


void Sudoku::giveQuestion(){

	int question[81] = {

        8,0,0,4,0,6,0,0,7,
        0,0,0,0,0,0,4,0,0,
        0,1,0,0,0,0,6,5,0,
        5,0,9,0,3,0,7,8,0,
        0,0,0,0,7,0,0,0,0,
        0,4,8,0,2,0,1,0,3,
        0,5,2,0,0,0,0,9,0,
        0,0,1,0,0,0,0,0,0,
        3,0,0,9,0,2,0,0,5,
	};
	
	int i=0;
	
	while(i<=80){
		
		printf("%d",question[i]);
		(i+1)%9==0?printf("\n"):printf(" ");
		i++;
	}
}


void Sudoku::readIn(){
	
	int i=0;

	while(i<81){

		scanf("%d", &cube[i]);
		i++;
	}

}

/*
void sudoku::solve(){

	int i=0,j=0;
	
	int zero=0;

	for(i=0;i<81;i++){

			if(cube[i]==0) zero++;
	}

//	printf("%d",zero);

	int zeroSite[zero];

	for(i=0;i<81;i++){

		if(cube[i]==0){

			zeroSite[j]=i;
			j++;
		}
	}

/*		for(i=0;i<zero;i++){

			printf("%d\n", zeroSite[i]);
		}

	int cubeElement[zero][9];
	
	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			cubeElement[i][j]=j+1;
		}
	}//OK

	i=0; //test
	j=0;

	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			printf("%d",cubeElement[i][j]);
			(j+1)%9==0?printf("\n"):printf(" ");
		}
	} 

	int k,l;

	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			for(k=0;k<9;k++){					

				if(cubeElement[i][j]==cube[(zeroSite[i]/9)*9+k]){
	
					cubeElement[i][j]=0;
				}
				if(cubeElement[i][j]==cube[zeroSite[i]%9+k*9]){
	
					cubeElement[i][j]=0;			
				}
				if(cubeElement[i][j]==cube[((zeroSite[i])/27)*27+((zeroSite[i]%9)/3)*3+k%3+k/3*9]){
	
					cubeElement[i][j]=0;			
				}			
			}
		}	
	}
	int Zero=82;
	bool element[9][9][9];

	while(Zero!=zero&&zero){

		Zero=zero;

		for(i=0;i<9;i++){

			for(j=0;j<9;j++){

				
			}	
		}
	}
	
	int whereElement[zero];

	for(i=0;i<zero;i++){

		whereElement[i]=0;
	}

	for(i=0;i<zero;i++){

		for(j=whereElement[i];j<9;j++){

			if(cubeElement[i][j]!=0){
					
				cube[zeroSite[i]]=cubeElement[i][j];
				whereElement[i]=j;
				break;
			}
		}

		for(k=0;k<9;k++){		

			if(cube[zeroSite[i]]==cube[(zeroSite[i]/9)*9+k]){
	
				whereElement[i]++;
				i--;
				break;
			}
			if(cube[zeroSite[i]]==cube[zeroSite[i]%9+k*9]){
		
				whereElement[i]++;
				i--;
				break;
			}
			if(cube[zeroSite[i]]==cube[((zeroSite[i])/27)*27+((zeroSite[i]%9)/3)*3+k%3+k/3*9]){
		
				whereElement[i]++;
				i--;
				break;
			}
		}		
	}




}
*/


/*	for(i=0;i<zero;i++){

		for(j=0;j<9;j++){

			printf("%d", cubeElement[i][j]);
			(j+1)%9==0?printf("\n"):printf(" ");
		}
	}
*/



void Sudoku::changeNum(int a, int b){
	
	if(a<=0||b<=0||a>9||b>9){

		printf("ERROR");
		exit(1);
	}
	
	int i=0;
	
	while(i<=80){
	
		if(cube[i]==a)	cube[i]=b;
		else if(cube[i]==b)	cube[i]=a;	
		i++;
	}

}


void Sudoku::changeRow(int a, int b){

	if(a<0||b<0||a>2||b>2){

		printf("ERROR");
		exit(1);
	}

	int change;
	int i,j;

	for(i=0;i<27;i++){

			change=cube[27*a+i];
			cube[27*a+i]=cube[27*b+i];
			cube[27*b+i]=change;
	}

}


void Sudoku::changeCol(int a, int b){

	if(a<0||b<0||a>2||b>2){

		printf("ERROR");
		exit(1);
	}
	
	int change;
	int i,j;

	for(i=0;i<9;i++){

		for(j=0;j<3;j++){
		
			change=cube[9*i+3*a+j];
			cube[9*i+3*a+j]=cube[9*i+3*b+j];
			cube[9*i+3*b+j]=change;
		}
	}
}


void Sudoku::rotate(int n){
	
	if(n<0||n>100){

		printf("ERROR");
		exit(1);
	}
	
	n=n%4;

	int cubeNew[81];
	int i,j;
	
	i=0;
	
	while(i<81){

		cubeNew[i]=0;
		i++;
	}

	if(n==1){
	
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(j-i))]=cube[9*i+j];
			}//rotate 90 degree
		}
	}
	else if(n==2){
		
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(8-j-i))]=cube[9*i+j];
			}//rotate 180 degree
		}
	}
	else if(n==3){
		
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((0-j+i)+9*(8-j-i))]=cube[9*i+j];
			}//rotate 270 degree
		}
	}
	else{
		
		for(i=0;i<81;i++){
		
			cubeNew[i]=cube[i];
		}
	}
	
	i=0;

	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}

}


void Sudoku::flip(int n){

	if(n<0||n>1){

		printf("ERROR");
		exit(1);
	}

	int i,j;
	int cubeNew[81];

	if(n==1){

		for(i=0;i<9;i++){
			
			for(j=0;j<9;j++){

				cubeNew[9*i+j+8-2*j]=cube[9*i+j];
			}//vertically
		}
	}
	else{

		for(i=0;i<9;i++){

			for(j=0;j<9;j++){

				cubeNew[9*i+j+9*(8-2*i)]=cube[9*i+j];
			}//horizontally
		}
	}
	
	i=0;

	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}
	
}


void Sudoku::transform(){

	readIn();

	srand(time(NULL));
	
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);

	printS();	
}


void Sudoku::printS(){
	
	int i=0;
	
	while(i<=80){
		
		printf("%d",cube[i]);
		(i+1)%9==0?printf("\n"):printf(" ");
		i++;
	}
	printf("\n");
}

void Sudoku::solve(){

	int i,j;

	int cubeNew[9][9];

	for( i=0;i<9;i++){

		for( j=0;j<9;j++){

			cubeNew[i][j]=cube[9*i+j];
		}
	}
//-----------------------------------------------------------------
	int k;

    bool num[9][9][9];

    for(i=0;i<9;i++){

        for(j=0;j<9;j++){

            if(cubeNew[i][j]){

                for(k=0;k<9;k++){

                    num[i][j][k]=false;
                	num[i][j][cubeNew[i][j]-1]=true;
            	}
			}
            else{

                for(k=0;k<9;k++){

                    num[i][j][k]=true;
				}
			}
        }

    }

//-------------------------------------------------------------------
    int zero=82,Zero=81;
	int row,sum,ans,col;
	int m,n;

    while(Zero!=zero&&zero){

        Zero=zero;

        for(row=0;row<9;row++){

            for(col=0;col<9;col++){

                if(!cubeNew[row][col]){

                    for(i=0;i<9;i++){//TEST COL

                        if(cubeNew[i][col]){ 
						
							num[row][col][cubeNew[i][col]-1]=false;
						}
					}
                    for(j=0;j<9;j++){//TEST ROW

                        if(cubeNew[row][j]){
					
							num[row][col][cubeNew[row][j]-1]=false;
						}
					}
                    for(i=0;i<3;i++){//TEST 3*3

                    	for(j=0;j<3;j++){

                            if(cubeNew[i-(row%3)+row][j+col-(col%3)]){ 

								num[row][col][cubeNew[i-(row%3)+row][j+col-(col%3)]-1]=false;
							}
						}
					}
					//--------------------------------------------------				
                    sum=0;
                    for(k=0;k<9;k++){

                        if(num[row][col][k]){

                            sum++;
                            ans=k+1;
                        }
                    }

                    if(sum==1){ 
				
						cubeNew[row][col]=ans;
					}	
				}
            }
        }
	
	zero=0;

        for(i=0;i<9;i++){

            for(j=0;j<9;j++){

                if(!cubeNew[i][j]) zero++;
			}
		}
      

	for(i=0;i<9;i++){

		for(j=0;j<9;j++){

			if(cubeNew[i][j]){

				for(m=0;m<9;m++){

					if(cubeNew[m][j]==cubeNew[i][j]&&i!=m){

							printf("2\n");
							exit(1);
					}
				}
				for(n=0;n<9;n++){

                        if(cubeNew[i][n]==cubeNew[i][j]&&j!=n){

                            printf("2\n");
							exit(1);
                        }
					}
				for(m=0;m<3;m++){

					for(n=0;n<3;n++){
	
						if(cubeNew[i-(i%3)+m][j-(j%3)+n]==cubeNew[i][j]&&i!=(i-(i%3)+m)&&j!=j- (j%3)+n){

							printf("2\n");
							exit(1);
						}
					}
				}
			}
		}
	}
}
//-----------------------------------------------------------------------------
    if(zero){

        printf("0\n");
		exit(1);
    }
	else{
    
		printf("1\n");
	}

	
	for(i=0;i<9;i++){

		for(j=0;j<9;j++){

			cube[9*i+j]=cubeNew[i][j];
		}
	}

	printS();
	
}
