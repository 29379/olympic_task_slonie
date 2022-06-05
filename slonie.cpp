#include <iostream>
#include <climits>

const int MAX_N = 1000000;
typedef long long int LL;


using namespace std;


int min(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}


int main()
{
    int n = 0;
    int lightest_overall = INT_MAX;
    LL result = 0;
    cin >> n;

    int* default_arrangement = new int[n];
    int* target_arrangement = new int[n];
    int* mass_values = new int[n];
    bool* arr = new bool[n];

    for (int i = 0; i < n; i++){
        arr[i] = false;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> mass_values[i];
        lightest_overall = min(lightest_overall, mass_values[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> default_arrangement[i];
        --default_arrangement[i];
    }

    for (int i = 0, k = 0; i < n; ++i)
    {
        cin >> k;
        target_arrangement[--k] = default_arrangement[i];
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (!arr[i]){
            LL sum = 0;
            int lightest_in_the_cycle = INT_MAX;
            int c = 0;
            int k = i;

            do {
            sum += mass_values[k];
            lightest_in_the_cycle = min(lightest_in_the_cycle, mass_values[k]);
            k = target_arrangement[k];
            arr[k] = true;
            c++;
            } while (i != k);

            result += min(
                sum + (c-2) * lightest_in_the_cycle,
                sum + lightest_in_the_cycle + (c+1) * lightest_overall);
            }
    }

    cout << result << endl;

    delete[] default_arrangement;
    delete[] target_arrangement;
    delete[] mass_values;
    delete[] arr;

    return 0;
}