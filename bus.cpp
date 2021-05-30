#include <iostream>
using namespace std;


#define MAX_BUS_SIZE 50

struct Result
{
    unsigned int bus_count = 1;
    unsigned int free_seats;
};

Result compute_bus_capcity(unsigned int passengers_available);

int main(int args, char **argv)
{

    unsigned int total_passengers;
    Result result;

    cout << "\tBUS SOFTWARE\n";
    cout << "\tThis application has been designed to help you estimate the number of buses your company will\n";
    cout << "\tneed at any point in time, given the total number of passengers available at your station.\n\n";

    cout << "\tEnter total passengers available at your station: ";
    cin >> total_passengers;

    result = compute_bus_capcity(total_passengers);

    cout << "\tYour company will need " << result.bus_count << " buses to convey " << total_passengers << " passengers. \n";
    cout << "\tThe last bus will have " << result.free_seats << " availbale.\n";

    return 0;
}

Result compute_bus_capcity(unsigned int passengers_available)
{
    Result result;
    while (MAX_BUS_SIZE % passengers_available > 0 && passengers_available > MAX_BUS_SIZE)
    {
        passengers_available -= MAX_BUS_SIZE;
        result.bus_count++;
    }
    result.free_seats = MAX_BUS_SIZE % passengers_available;

    return result;
}