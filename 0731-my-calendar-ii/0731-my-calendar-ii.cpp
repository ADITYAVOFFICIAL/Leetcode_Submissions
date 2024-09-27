using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> booked;   // List of all booked intervals
    vector<pair<int, int>> overlaps; // List of intervals where double bookings occur
    
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        // Check if the new event causes a triple booking
        for (auto [s, e] : overlaps) {
            if (max(start, s) < min(end, e)) {
                // If there is any overlap with the existing double bookings, return false
                return false;
            }
        }
        
        // Update the overlaps list for any double bookings caused by this new event
        for (auto [s, e] : booked) {
            if (max(start, s) < min(end, e)) {
                // Calculate the overlapping interval and add it to overlaps
                overlaps.push_back({max(start, s), min(end, e)});
            }
        }
        
        // Add the current event to the booked list
        booked.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
