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
    cout << "Display tweets by value" << endl;
    cout << string(15,'*') <<tweet1.id << string(15,'*') <<endl;
    cout << tweet1.msg << endl;
    cout << tweet1.author << "\t" << tweet1.timestamp <<endl;
    cout << "(" << tweet1.location.lat << ", " << tweet1.location.lng << ")" <<endl;
    cout << string(31,'*') << endl;
}
void display_tweet_by_reference(const tweet &tweet1){
    cout << "Display tweets by reference" << endl;
    cout << string(15,'*') <<tweet1.id << string(15,'*') <<endl;
    cout << tweet1.msg << endl;
    cout << tweet1.author << "\t" << tweet1.timestamp <<endl;
    cout << "(" << tweet1.location.lat << ", " << tweet1.location.lng << ")" <<endl;
    cout << string(31,'*') << endl;
}

void display_tweet_by_pointer(const tweet *tweet1){
    cout << "Display tweets by pointer" << endl;
    cout << string(15,'*') << tweet1->id << string(15,'*') <<endl;
    cout << tweet1->msg << endl;
    cout << tweet1->author << "\t" << tweet1->timestamp <<endl;
    cout << "(" << tweet1->location.lat << ", " << tweet1->location.lng << ")" <<endl;
    cout << string(31,'*') << endl;
}

void display_tweets_by_array(const tweet tweetArr[], int size){
    cout << "Display tweets in array" << endl;
    for(int i = 0; i< size; i++){
        display_tweet_by_reference(tweetArr[i]);
    }
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

    tweets[1].msg = "My second tweet";
    tweets[1].author = "Ida";
    tweets[1].id = 2;
    tweets[1].timestamp = 1709130764;
    tweets[1].location.lat = 59.5923569;
    tweets[1].location.lng = 1.326927926;

    tweets[2].msg = "My third tweet";
    tweets[2].author = "Cam+";
    tweets[2].id = 3;
    tweets[2].timestamp = 1709130764;
    tweets[2].location.lat = 59.5923569;
    tweets[2].location.lng = 1.326927926;

    delete[] tweets;
    tweets = nullptr;

    tweet arr[2]{tweets[1],tweets[2]};

    display_tweets_by_array(arr,2);

    return 0;
}
