#include<stdio.h>
#define N 10
void swap();
void order1();
void order2();
void order3();
void order4();
void export();

//Êä³ö
void export(int *arr,int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

//Ë«²à
void order4(int *arr,int n) {
	int i;
	int j;
	int t;

	for(i=0; i<n/2; i++) {
		t = i;
		for(j=i+1;j<=n-i-1;j++) {
			if(arr[t]<arr[j]) {
				t = j;
			}
		}
		if(t != i) {
			swap(&arr[t],&arr[i]);
		}

		t=n-i-1;
		for(j=i+1;j<n-i-1;j++) {
			if(arr[t]<arr[j]) {
				t = j;
			}
		}
		if(t != n-i-1) {
			swap(&arr[t],&arr[n-i-1]);
		}
	}
}

//²åÈë
void order3(int *arr,int n) {
	int i;
	int j;
	int t;

	for(i=1; i<n; i++) {
		t = arr[i];
		for(j=i-1; j>=0&&t>arr[j]; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = t;
	}
}

//Ñ¡Ôñ
void order2(int *arr,int n) {
	int i;
	int j;
	int t;

	for(i=0; i<n+1; i++) {
		t = i;
		for(j=i+1; j<n; j++) {
			if(arr[t] < arr[j]) {
				t = j;
			}
		}
		if(t != i) {
			swap(&arr[t],&arr[i]);
		}
	}
}
//Ã°ÅÝ
void order1(int *arr,int n) {
	int i;
	int j;

	for(i=0; i<n-1; i++) {
		for(j=0; j<n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

//½»»»
void swap(int *a,int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main() {
	int arr[N] = {1,2,3,4,5,6,7,8,9,0};

	order1(arr,N);
	export(arr,N);
	order2(arr,N);
	export(arr,N);
	order3(arr,N);
	export(arr,N);



	order4(arr,N);
	export(arr,N);

	return 0;
}