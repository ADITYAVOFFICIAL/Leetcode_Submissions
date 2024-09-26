class MyCalendar {
private:
    vector<pair<int, int>> bookings; // To store the booked intervals

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // Check for overlaps with existing bookings
        for (const auto& booking : bookings) {
            // If there is an overlap
            if (start < booking.second && end > booking.first) {
                return false; // Booking failed due to overlap
            }
        }
        // If no overlap, add the booking
        bookings.emplace_back(start, end);
        return true; // Booking successful
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */