%{
  #include<stdio.h>
  #include<math.h>
%}
%%
[\n]
[0-9]+ {return atoi(yytext);}

^[-+]?[0-9]*[.][0-9]+ {printf("Invalid.\n");
                       exit(0);}
%%

int main(){
    int NumGroups=yylex();
    if(NumGroups<=0){
        printf("Invalid.\n");
        exit(0);
    }
    int SmallNumGroups=999999;
    int GroupSize;
    while((GroupSize=yylex())>0){
        if(SmallNumGroups>GroupSize){
            SmallNumGroups=GroupSize;
        }
    }
    printf("\n%d\n",SmallNumGroups);
    yylex();
    return 0;
}
