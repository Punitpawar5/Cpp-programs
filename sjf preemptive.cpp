#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process 
{
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};

bool compareArrivalTime(const Process& a, const Process& b) 
{
    return a.arrivalTime < b.arrivalTime;
}

int main() 
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

        for (int i = 0; i < n; ++i) {
        processes[i].processID = i + 1;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;

    while (!processes.empty()) {
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.remainingTime < b.remainingTime;
        });

        Process& currentProcess = processes.front();

        if (currentProcess.remainingTime <= 0) {
            processes.erase(processes.begin());
            continue;
        }

        cout << "Executing process " << currentProcess.processID << " at time " << currentTime << endl;
        currentTime++;
        currentProcess.remainingTime--;

        if (currentProcess.remainingTime == 0) {
            processes.erase(processes.begin());
        }
    }

    return 0;
}


