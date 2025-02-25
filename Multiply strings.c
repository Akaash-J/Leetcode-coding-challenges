char* multiply(char* num1, char* num2) {
    if(strcmp(num1,"0")==0 || strcmp(num2,"0")==0){
        return strdup("0");
    }
    int len1= strlen(num1), len2 = strlen(num2);
    int result[len1+len2+1];
    memset(result,0,sizeof(result));
    for(int i=len1-1; i>=0; i--){
        for(int j=len2-1; j>=0; j--){
            int mul = (num1[i]-'0')*(num2[j]-'0');
            int sum = mul+result[i+j+1];
            result[i+j+1]=sum%10;
            result[i+j] += sum/10;
        }
    }

    char *product = (char*)malloc(len1+len2+1);
    int k=0, index=0;
    while(result[k]==0 && k<len1+len2) k++;
    while(k<len1+len2){
        product[index++] = result[k++]+'0';
    }
    product[index]='\0';
    return product;
}
