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
