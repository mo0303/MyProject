#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int r, c, i, j, k, n, p, z;
float a[100][100], b[100][100], sum[100][100], Det, g= 0, ratio, o;
//#######################################?????????????????????????????############################################
void plus();
void multiplication();
void minus();
void division();
void det();
void detforsquare();
void inverse();
void inverseforsquare();
int Loop();
//#######################???????????????###############################
int main() {
    system("COLOR b1");  /// ????????????????????????????
    int t;
    printf("**********  Welcome to the Matrix Calculator  **********\n\n");
    printf("Choose the menu :\n\n\t1.Square Matrix for Det and Inverse\n\n\t2.Enter You row and column\n\n\t3.Quit\n\n");
    scanf("%d", &p); /// ??????????????????
if (p == 1)
    {
    system("COLOR b1"); 
    printf("\nEnter size of a Square Matrix (Must more than 1) : \n\n");
    scanf("%d", &n);
 
    if (n > 1){
    printf("\nEnter the number of %d x %d matrix: \n" ,n,n);
    for(i = 0 ;i < n;i++)
      for(j = 0;j < n;j++)
       scanf("%f", &a[i][j]);   ////?????????????????????
 
    printf("\nThe matrix is\n");
    for(i = 0;i < n; i++){
      printf("\n");
      for(j = 0;j < n; j++)
        printf("%.2f\t", a[i][j]);
    }
        printf("\n\nDo you want to\n\n\t1.Determinant\n\n\t2.Inverse\n\n"); 
        scanf ("%d",&t);
        if (t == 1)
        {
        detforsquare(); //// ??????????????????????????
        }
        else if (t == 2)
        {
        inverseforsquare();
        }
        else {
           printf("\nPlease select again.\n\n");
           return main();  //// ?????????????????
             }        
        }
        else {
           printf("\nPlease select again.\n\n");
           return main();
        }
    }  
else if (p == 2){
    system("COLOR b0");
    printf("\nEnter the number of rows (between 1 and 100): ");
    scanf("%d", &r);
    printf("\nEnter the number of columns (between 1 and 100): ");
    scanf("%d", &c);
    printf("\nRow and Column are %d  %d\n",r,c);
    printf("\nEnter number of 1st matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            printf("Enter number a [%d][%d]: ", i , j );
            scanf("%f", &a[i][j]);
        }
 
    printf("Enter number of 2nd matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            printf("Enter number b [%d][%d]: ", i , j);
            scanf("%f", &b[i][j]);
        }
        printf("\nEntered matrix 1st: \n");
    for (i = 0; i < r; i++){
    
        printf("\n");
        for (j = 0; j < c; j++) {
            printf("%.2f\t", a[i][j]);
            
            }
        }
        printf("\nEntered matrix 2nd: \n");
    for (i = 0; i < r; i++){
    
    printf("\n");
        for (j = 0; j < c; j++) {
            printf("%.2f\t", b[i][j]);
           
            }
        }
    printf("\n\nDo you want to \n\n\t1.Addition\n\n\t2.Subtraction\n\n\t3.Multiplication\n\n\t4.Division\n\n\t5.Determinant (Row and Column must be Equal and Must more than 1)\n\n\t6.Inverse (Row and Column must be Equal and Must more than 1)\n\n");
    scanf ("%d",&t);
        if (t == 1)
        {
        plus();
        }
        else if (t == 2)
        {
        minus();
        }
        else if (t == 3)
        {
        multiplication();
        }
        else if (t == 4)
        {
        division();
        }
        else if (t == 5)
        {
            if (r == c && (r > 1 && c > 1)){
                det();
            }
            else{
                 printf("\nRow and Column must be Equal and Must more than 1\n");
                 printf("\nPlease select again.\n\n");
                 return main();
            }
        
        }
        else if (t == 6)
        {
        if (r == c && (r > 1 && c > 1)){
                inverse();
            }
            else{
                 printf("\nRow and Column must be Equal and Must more than 1\n");
                 printf("\nPlease select again.\n\n");
                 return main();
            }
        }
else {
         
           printf("\nPlease select again.");
           Loop ();
     }
        
       
    }
    else if (p == 3){
    return 0;
    }
    else {   
           printf("\nPlease select again.");
           return main();
           }
}
////////??????????????????////////
void plus()
{
 
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
 
    printf("\nSum of two matrix is: \n");
    for (i = 0; i < r; i++){
       printf("\n");
        for (j = 0; j < c; j++) {
            printf("%.2f   ", sum[i][j]);
            }
        }
 
    Loop ();
}
//////////////?????????????????///////////////
void minus()
{
 
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] - b[i][j];
        }
 
    
    printf("\nSum of two matrix is: \n");
    for (i = 0; i < r; i++){
    
       printf("\n");
        for (j = 0; j < c; j++) {
            printf("%.2f\t", sum[i][j]);
            }
        }
        
    Loop (); /////// ????????????????????????????????? Loop///////
}
//////////////??????????????????///////////////
void multiplication()
{
    for(i = 0; i < r; i++){
    
        for(j = 0; j < c; j++){
 
        sum[i][j] = 0;
 
            for(k = 0; k < r && k < c; k++){
 
                sum[i][j] = sum[i][j] + (a[i][k] * b[k][j]);
                
            }
        }
    }
 
    printf("\nSum of two matrix is: \n");
    for (i = 0; i < r; i++){
    
      printf("\n");
        for (j = 0; j < c; j++) {
            printf("%.2f\t", sum[i][j]);
            }
    }
 
    Loop ();
}
//////////////??????????????????///////////////
void division()
{
 
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++){
            sum[i][j] = a[i][j]/b[i][j];
        }
 
    printf("\n\nSum of two matrix is : \n");
    for (i = 0; i < r; i++){
    
         printf("\n");
        for (j = 0; j < c; j++) {
            printf("%.2f\t", sum[i][j]);
        }
    }
    Loop ();
}
//////////////??????????????? Det ???????????????????????????///////////////
void det()
{
    Det = 1;
    int y;
    printf("\nDet of 1st or 2nd \n\n");
    scanf ("%d",&y);
    if (y == 1){
    
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
            if(j>i){
                ratio = a[j][i]/a[i][i];
                for(k = 0; k < r && k < c; k++){
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
  
    for(i = 0; i < c; i++)
        Det = Det * a[i][i];
        printf("\nDet of  matrix is :\n\n");
        printf("\t");
        printf("%.2f ", Det);
 
        Loop();
}
        
    else if (y == 2){
 
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
            if(j>i){
                ratio = b[j][i]/b[i][i];
                for(k = 0; k < r && k < c; k++){
                    b[j][k] = b[j][k] - ratio * b[i][k];
                }
            }
        }
    }
  
    for(i = 0; i < c; i++)
        Det = Det * b[i][i];
        printf("\nDet of  matrix is :\n\n");
        printf("\t");
        printf("%.2f ", Det);
 
            Loop();
    }
            else{
                system("COLOR e4");
                printf("\nPlease select again.\n");
                return det();
            }
}
//////////////??????????????? Det ?????????????????????/////////////// 
void detforsquare()
{
    
     Det = 1;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
            if(j>i){
                ratio = a[j][i]/a[i][i];
                for(k = 0; k < n; k++){
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
  
    for(i = 0; i < n; i++)
        Det = Det * a[i][i];
        printf("\nDet of  matrix is :\n\n");
        printf("\t");
        printf("%.2f ", Det);
 
            Loop();
}
//////////////??????????????? inverse ???????????????????????????///////////////
void inverse()
{
    int u;
    printf("\nInverse of 1st or 2nd \n\n");
    scanf ("%d",&u);
    if (u == 1){
    for(i = 0; i < r; i++){
        for(j = c; j < 2*c; j++){
            if(i==(j-c))
                a[i][j] = 1.0;
            else
                a[i][j] = 0.0;
        }
    }
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(i!=j){
                ratio = a[j][i]/a[i][i];
                for(k = 0; k < 2*r && k < 2*c; k++){
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }
    for(i = 0; i < r; i++){
        o = a[i][i];
        for(j = 0; j < 2*c; j++){
            a[i][j] /= o;
        }
    }
    printf("\n\tThe inverse matrix is: \n\n");
    for(i = 0; i < r; i++){
        printf("\t");
        for(j = c; j < 2*c; j++){
            printf("%.2f", a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    }
    else if (u == 2){
    for(i = 0; i < r; i++){
        for(j = c; j < 2*c; j++){
            if(i==(j-c))
                b[i][j] = 1.0;
            else
                b[i][j] = 0.0;
        }
    }
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(i!=j){
                ratio = b[j][i]/b[i][i];
                for(k = 0; k < 2*r && k < 2*c; k++){
                    b[j][k] -= ratio * b[i][k];
                }
            }
        }
    }
    for(i = 0; i < r; i++){
        o = b[i][i];
        for(j = 0; j < 2*c; j++){
            b[i][j] /= o;
        }
    }
    printf("\n\tThe inverse matrix is: \n\n");
    for(i = 0; i < r; i++){
        printf("\t");
        for(j = c; j < 2*c; j++){
            printf("%.2f", b[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    }
    else {
        system("COLOR e4");
        printf("\nPlease select again,\n");
        return inverse();
    }
    Loop();
}
//////////////??????????????? inverse ?????????????????????///////////////
void inverseforsquare()
{
 
    for(i = 0; i < n; i++){
        for(j = n; j < 2*n; j++){
            if(i==(j-n))
                a[i][j] = 1.0;
            else
                a[i][j] = 0.0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i!=j){
                ratio = a[j][i]/a[i][i];
                for(k = 0; k < 2*n; k++){
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }
    for(i = 0; i < n; i++){
        o = a[i][i];
        for(j = 0; j < 2*n; j++){
            a[i][j] /= o;
        }
    }
    printf("\n\tThe inverse matrix is: \n\n");
    for(i = 0; i < n; i++){
        printf("\t");
        for(j = n; j < 2*n; j++){
            printf("%.2f", a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    Loop();
}
//////////////??????????????? Loop///////////////
int Loop ()
{
system("COLOR b1"); 
char l;
    printf("\n\nDo you want to continue using the program? .(Y/N) : \n\n");
    scanf("%s",&l);
    
        switch (l) {
        case 'Y': 
                system("cls");  ///// ?????????????????? ////
                return main();
                break;
        case 'y': 
                system("cls");
                return main();
                break;
        case 'N': 
                system("COLOR b1");
                printf("\nThank You.");
                return 0; /////// ????????????? ///////
        case 'n':
                system("COLOR b1"); 
                printf("\nThank You.");
                return 0;
        default:
                Loop();
        
        }           
}   


