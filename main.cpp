#include <iostream>

using namespace std;
struct GeoLocation{
    double lat;
    double lng;
};

struct tweet{
    string msg;
    string author;
    int id;
    unsigned long timestamp;
    GeoLocation location;
};
void display_tweet_by_value(tweet tweet1){
    cout << string(15,'*') <<tweet1.id << string(15,'*') <<endl;
    cout << tweet1.msg << endl;
    cout << tweet1.author << "\t" << tweet1.timestamp <<endl;
    cout << "(" << tweet1.location.lat << ", " << tweet1.location.lng << ")" <<endl;
    cout << string(31,'*') << endl;
}
void display_tweet_by_reference(const tweet &tweet1){
    cout << string(15,'*') <<tweet1.id << string(15,'*') <<endl;
    cout << tweet1.msg << endl;
    cout << tweet1.author << "\t" << tweet1.timestamp <<endl;
    cout << "(" << tweet1.location.lat << ", " << tweet1.location.lng << ")" <<endl;
    cout << string(31,'*') << endl;
}

void display_tweet_by_pointer(const tweet *tweet1){
    cout << string(15,'*') << tweet1->id << string(15,'*') <<endl;
    cout << tweet1->msg << endl;
    cout << tweet1->author << "\t" << tweet1->timestamp <<endl;
    cout << "(" << tweet1->location.lat << ", " << tweet1->location.lng << ")" <<endl;
    cout << string(31,'*') << endl;
}

int main() {
    tweet tweet1;
    tweet1.msg = "My first tweet";
    tweet1.author = "Ben";
    tweet1.id = 1;
    tweet1.timestamp = 1709130764;
    tweet1.location.lat = 59.5923569;
    tweet1.location.lng = 1.326927926;

    display_tweet_by_value(tweet1);
    display_tweet_by_reference(tweet1);
    display_tweet_by_pointer(&tweet1);

    tweet *tweets = new tweet[3];
    tweets[0] = tweet1;

    delete[] tweets;
    tweets = nullptr;

    tweets[1].msg = "My first tweet";
    tweets[1].author = "Ben";
    tweets[1].id = 1;
    tweets[1].timestamp = 1709130764;
    tweets[1].location.lat = 59.5923569;
    tweets[1].location.lng = 1.326927926;
    return 0;
}
