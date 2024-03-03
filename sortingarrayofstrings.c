#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//apparently u can sort lexicographically strings by just using strcmp
int lexicographic_sort(const char* a, const char* b) {
    int i,len, ok=0;
    /*if(strlen(a)<strlen(b))
        len=strlen(a);
        else
            len=strlen(b);
    for(i=0;i<len;i++)
    {
        if(a[i]==b[i])
            continue;
        if(a[i]>b[i])
            ok=1; 
    }
    */
    if(strcmp(a,b)>0)
    ok=1;
    if(ok)
        return 1;
    else
        return 0;
        
}

int lexicographic_sort_reverse(const char* a, const char* b) {
int i, len, ok=0;
/*
    if(strlen(a)<strlen(b))
        len=strlen(a);
        else
            len=strlen(b);
    for(i=0;i<len;i++)
    {
        if(a[i]==b[i])
            continue;

        if(a[i]<b[i])
            ok=1;      
    }*/
    if(strcmp(a,b)<0)
    ok=1;
    if(ok)
        return 1;
    else
        return 0;
        
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    float n_a=0, n_b=0;
	int ap, s_a, s_b, ok=0;
      
   		for(int i=0;i<strlen(a);i++)
        {
        	ap=0;
            for(int j=0;j<strlen(a);j++)
            {
                if(a[i]==a[j])
                {
                n_a=n_a+1;
                ap++;
            	}
            }
            if(ap>1)
            {
            	n_a=n_a-(float)ap;
            	n_a=n_a+1/(float)ap;
			}
        }
        
        for(int i=0;i<strlen(b);i++)
        {
        	ap=0;
            for(int j=0;j<strlen(b);j++)
            {
                if(b[i]==b[j])
                {
                n_b=n_b+1;
                ap++;
            	}
            }
            if(ap>1)
            {
            n_b=n_b-(float)ap;
            n_b=n_b+1/(float)ap;
        	}
        }
    s_a=roundf(n_a);
    s_b=roundf(n_b);
    
            
    if(s_a>s_b)
            ok=1;
        else 
            if(s_b=s_a)
            	if(strcmp(a,b)>0)
            	ok=1;
    
    if(ok)
    	return 1;
    	else
    	return 0;
     
}

int sort_by_length(const char* a, const char* b) {
    int ok=0;
    
    if(strlen(a)>strlen(b))
        ok=1;
    else 
    if(strlen(a)==strlen(b))
    {
        if(strcmp(a,b)>0)
        ok=1;
    }
    if(ok)
        return 1;
    else 
        return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char *temp;
    temp=(char*)malloc(100*sizeof(char));
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
        if(cmp_func(arr[i],arr[j])==1)
        {
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],temp);
        }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) =(char*) malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) =(char*) realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
