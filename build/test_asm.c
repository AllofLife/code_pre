void strcpy(char x[],char y[]){
    int i;
    i = 0;
    while ( y[i] != '\0')
    {
       x[i] = y[i];
       i++;
    }
    
}
int main(){
    char x[5];
    strcpy(x,"123");
}