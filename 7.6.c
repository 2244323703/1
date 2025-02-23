#include<stdio.h>
struct record{
    char name[20];
    int score;
    }a[21];
    
    
void swapRecord(struct record *a, struct record *b) {
    struct record temp = *a;
    *a = *b;
    *b = temp;
}

int sum(struct record records[], int n) {
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(records[i].name, records[j].name) == 0) {
                records[i].score += records[j].score;
                records[j].score = 0;
                strcpy(records[j].name, "");
            }
        }
    }
    
    int k = 0;
    
    for (i = 0; i < n; i++) {
        if (records[i].score != 0) {
            swapRecord(&records[i], &records[k]);
            k++;
        }
    }
    return k;
}

void bubbleSort(struct record records[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (records[j].score < records[j + 1].score) {
                swapRecord(&records[j], &records[j + 1]);
            }
        }
    }
}


int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%s %d",a[i].name ,&a[i].score );
	}
	
	int sumsum=sum(a,n);
	
	bubbleSort(a,sumsum);
	
	for (int i = 0; i < sumsum ; i++) {
        printf("%s %d\n", a[i].name, a[i].score);
    }

	return 0;
	
}	  
