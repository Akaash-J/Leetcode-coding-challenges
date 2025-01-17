/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *d2l[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char **result, int *returnSize, char *current, int index, char* digits){
    if(index==strlen(digits)){
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    char *letters = d2l[digits[index]-'0'];
    for(int i=0; i<strlen(letters); i++){
        current[index] = letters[i];
        backtrack(result, returnSize, current, index+1, digits);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if(strlen(digits)==0) return NULL;
    int maxcombination = 1;
    for(int i=0 ; i<strlen(digits); i++){
        maxcombination *= strlen(d2l[digits[i]-'0']);
    }
    char **result = (char**)malloc(maxcombination*sizeof(char *));
    char *current = (char*)malloc((strlen(digits)+1)*sizeof(char));
        current[strlen(digits)] = '\0'; 
    backtrack(result, returnSize, current, 0, digits);
    free (current);
    return result;
}
