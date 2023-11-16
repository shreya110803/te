// ---------------Best Fit----------------

#include<iostream>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

// Driver Method
int main() {
    int m, n;

    cout << "Enter the number of blocks: ";
    cin >> m;

    int blockSize[m];
    cout << "Enter the block sizes: ";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> n;

    int processSize[n];
    cout << "Enter the process sizes: ";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    bestFit(blockSize, m, processSize, n);

    return 0;
}
// int blockSize[] = {100, 500, 200, 300, 600};
// int processSize[] = {212, 417, 112, 426};








// ----------------First Fit-----------------

#include<bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n)
{	
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (blockSize[j] >= processSize[i]){	
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++){
		cout << " " << i+1 << "\t\t"<< processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}
int main()
{
	// int blockSize[] = {10, 20, 30, 40, 50};
	// int processSize[] = {8, 17, 38, 60};
	int m, n;
    cout << "Enter the number of blocks: ";
    cin >> m;
    int blockSize[m];
    cout << "Enter the block sizes:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }
    cout << "Enter the number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter the process sizes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }
    firstFit(blockSize, m, processSize, n);
	return 0 ;
}




// ---------------------Next Fit----------------------

#include <bits/stdc++.h>
using namespace std;

void NextFit(int blockSize[], int m, int processSize[], int n)
{	
	int allocation[n], j = 0, t = m - 1;	
	memset(allocation, -1, sizeof(allocation));
	for(int i = 0; i < n; i++){
		while (j < m){
			if(blockSize[j] >= processSize[i]){
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				t = (j - 1) % m;
				break;
			}
			if (t == j){
			
				t = (j - 1) % m;
				break;
			}
			j = (j + 1) % m;
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++) {
		cout << " " << i + 1 << "\t\t\t\t" << processSize[i]
			<< "\t\t\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}
int main()
{
	// int blockSize[] = { 5, 10, 20 };
	// int processSize[] = { 10, 20, 5 };
	int m, n;
    cout << "Enter the number of blocks: ";
    cin >> m;
    int blockSize[m];
    cout << "Enter the block sizes:\n";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }
    cout << "Enter the number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter the process sizes:\n";
    for (int i = 0; i < n; i++) 
	{
        cin >> processSize[i];
    }
    NextFit(blockSize, m, processSize, n);
	return 0;
}







// ---------------Worst Fit----------------

#include<bits/stdc++.h>
using namespace std;

void worstFit(int blockSize[], int m, int processSize[],int n){
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i=0; i<n; i++){		
		int wstIdx = -1;
		for (int j=0; j<m; j++){
			if (blockSize[j] >= processSize[i]){
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
		}		
		if (wstIdx != -1){
			allocation[i] = wstIdx;
			blockSize[wstIdx] -= processSize[i];
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}
int main()
{
	int m, n;
    cout << "Enter the number of blocks: ";
    cin >> m;
    int blockSize[m];
    cout << "Enter the block sizes:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }
    cout << "Enter the number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter the process sizes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }
    worstFit(blockSize, m, processSize, n);
	return 0 ;
}
// int blockSize[] = {100, 500, 200, 300, 600};
// int processSize[] = {212, 417, 112, 426};
