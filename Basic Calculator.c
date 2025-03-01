int calculate(char* s) {
    int len = strlen(s);
    char *stack = (char*)malloc(len*sizeof(char));
    int *numStack = (int*)malloc(len*sizeof(int));
      if (!stack || !numStack) {
        printf("Memory allocation failed\n");
        return -1;
    }
    int stackTop = -1;
    int numTop = -1;
    numStack[++numTop] = 0;int sign =1;
    int i=0;
    while(s[i]!='\0'){
        if(isdigit(s[i])){
            int num=0;
            while(isdigit(s[i])){
                num = num*10+(s[i++]-'0');
            }
            numStack[numTop] += sign*num;
        }else if(s[i]=='('){
            stack[++stackTop] = sign;
            numStack[++numTop] = 0;
            sign = 1;
            i++;
        }else if(s[i]==')'){
           
                int n1 = numStack[numTop--];
                int prevSign = stack[stackTop--];
                
                numStack[numTop] += prevSign*n1;
            i++;
        }else if(s[i]=='+' || s[i] =='-'){
            sign = (s[i]=='+')?+1:-1;
            i++;
        }
        else{
            i++;
        }
    }
    int res = numStack[numTop];
    free(numStack);
    free(stack);
    return res;
}
