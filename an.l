%{
#include<stdio.h>
#include<string.h>
char str[100];
int i=0;
int l =0;
%}
%%
[a-zA-z] {char c=yytext[0];
          l = strlen(str);
          if(isupper(c)){c += 32;}
          else{c -= 32;}
          str[l+1]=str[l];
          str[l]=c;
        }
[0-9] {i=1;}
[ ]   {l = strlen(str);
      str[l+1]=str[l];
      str[l]=' ';}
%%   

int main(){
  yylex();
  int le = strlen(str);
  str[le]='\0';
  if(i==0){
    printf("%s \n",str);
  }
  else{
    printf("%d \n",-1);
  }
    return 0;
}