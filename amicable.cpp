
#include <iostream>
#include <vector>
using namespace std;

int sumOfDivisors(int number)
{
    int sum = 0;

    for (int divisor = 1; divisor <= number / 2; divisor++)
    {
        if (number % divisor == 0)
        {
            sum += divisor;
        }
    }

    return sum;
}

int main()
{
    int startRange, endRange;

    cout << "Enter the starting and ending range: ";
    cin >> startRange >> endRange;

    vector<pair<int, int>> amicablePairs;

    for (int number = startRange; number <= endRange; number++)
    {
        int sum = sumOfDivisors(number);

        if (sum > number && sum <= endRange)
        {
            int secondSum = sumOfDivisors(sum);

            if (secondSum == number)
            {
                amicablePairs.push_back({number, sum});
            }
        }
    }

    cout << "Total Amicable Pairs: "
         << amicablePairs.size() << endl;

    for (int index = 0; index < amicablePairs.size(); index++)
    {
        cout << amicablePairs[index].first << " "
             << amicablePairs[index].second << endl;
    }

    return 0;
}
