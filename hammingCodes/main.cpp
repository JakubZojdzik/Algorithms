#include <bits/stdc++.h>
using namespace std;

constexpr size_t block_size = 64; // Put there any power of 2
int width = int(sqrt(block_size));
int guards = int(log2(block_size));

void print_bits(bitset<block_size> x)
{
    for (int i = 0; i * i < block_size; i++)
    {
        for (int j = 0; j * j < block_size; j++)
        {
            cout << x[i * width + j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    random_device r;
    bitset<block_size> message;
    default_random_engine generator(r());
    uniform_real_distribution<float> distribution(0, 2);

    for (size_t i = 0; i < block_size; i++)
        if (__builtin_popcount(i) > 1)
            message.set(i, int(distribution(generator)));

    cout << "Normal message:\n";
    print_bits(message);
    vector<bool> parity(guards);
    for (size_t i = 0; i < block_size; i++)
    {
        if (message[i])
        {
            int x = i;
            for (int j = 0; j < guards; j++)
            {
                if (x & 1)
                    parity[j] = !parity[j];
                x /= 2;
            }
        }
    }
    for (int i = 0; i < guards; i++)
        if (parity[i])
            message[1 << i] = 1;
    message[0] = (message.count() & 1);
    cout << "\nSafe message:\n";
    print_bits(message);

    int p;
    cout << "Choose bit's coordinates to broke (greater than 0):\n";
    cin >> p;
    if(p < int(block_size))
        message[p] = !message[p];
    cout << "\nbroken message:\n";
    print_bits(message);

    int result = 0;
    for (size_t i = 0; i < block_size; i++)
    {
        if (message[i])
            result ^= i;
    }
    if (result == 0 && (message.count() & 1) == 0)
        cout << "XOR says, that message isn't broken\n";
    else
        cout << "XOR says, that broken place is " << result << '\n';
}