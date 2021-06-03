/*
Starting with a 1-indexed array of zeros and a list of operations, 
for each operation add a value to each the array element between two given indices, inclusive. 
Once all operations have been performed, return the maximum value in the array.
n = 10
queries  = [[1,5,3],[4,8,7],[6,9,1]]
output = 10
The indices are
            a   b   k
            1   5   3
            4   8   7
            6   9   1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long arrayManipulation(long n, vector<vector<long>> queries)
{
    vector<long int> A(n, 0); // sum or difference of K's value in the vector
    long len = queries.size();
    for (long i = 0; i < len; i++)
    {
        //  step 1 as described above
        A[(queries[i][0]) - 1] = A[(queries[i][0]) - 1] + queries[i][2];
        if (queries[i][1] < n) // checking for segmentation fault
        {
            // step 2 as described above
            A[(queries[i][1])] = A[(queries[i][1])] - queries[i][2];
        }
    }
    long sum = 0, x = 0;
    // Step 3: Calculating maximum prefix array sum
    for (long i = 0; i < n; i++)
    {
        x = x + A[i];
        if (x > sum)
        {
            sum = x;
        }
    }
    return sum;
}
int main()
{
    cout << endl
         << arrayManipulation(5, {{1, 2, 100}, {2, 5, 100}, {3, 4, 100}}) << "\n";
    system("pause");
    return 0;
}