%{
#include <stdio.h>
int i=0;
%}

%%

[\n]

^[-+]?[0-9]*[.][0-9]+   {i=1;
                        return(atoi(yytext));} 

[0-9]+ {return atoi(yytext);} 

%%

int main(){
    float n,k;
    n=yylex();
    k=yylex();
    int x=(int)k;
    if(x==k){
        printf("%d\n",x);
    }
    else{
        printf("%0.2f\n",k);
    }
    if(i==0){
        if (k<n){
            printf("Thank you\n");
        }
        else{
            printf("Sorry\n");
        }
    }
    else{
        printf("Invalid\n.");
    }
     

    return 0;
}