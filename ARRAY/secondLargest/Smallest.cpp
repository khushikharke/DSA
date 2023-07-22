vector<int> getSecondOrderElements(int n, vector<int> a)

{

    int maxi = INT_MIN, mini = INT_MAX, mx = INT_MIN, mn = INT_MAX;

    for (int i = 0; i < n; i++)

    {

        maxi = max(maxi, a[i]);

        mini = min(mini, a[i]);
    }

    for (int i = 0; i < n; i++)

    {

        if (a[i] > mx && a[i] != maxi)

            mx = a[i];

        if (a[i] < mn && a[i] != mini)

            mn = a[i];
    }

    return {mx, mn};
}
