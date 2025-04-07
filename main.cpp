/*************************************************************************
** Author          : Caden Picard
** Program         : Social Media Account Functionality
** Date Created    : April 7, 2025
** Date Last Modified: April 7, 2025
** Key Components:
** 1. SocialMediaAccount<T>:
**    - Manages: Account handler (type T), arrays for followers and
**      followed users (up to global limits `maxFollowers`, `maxFollowed`),
**      counts for followers/followed, and a privacy flag (boolean).
**    - Provides: Constructors, getters/setters (excluding arrays),
**      functions to add followers/followed, and functions to display
**      followers/followed (respecting the privacy setting).
**
** 2. Twitter<T>:
**    - Adds: `retweetCount` (int) to track retweets.
**    - Adds: `RT()` function to increment `retweetCount`.
**    - Provides: Getters/setters for `retweetCount`.
**
** 3. Instagram<T>:
**    - Adds: `likeCount` (int) to track likes.
**    - Adds: `Like()` function to increment `likeCount`.
**    - Provides: Getters/setters for `likeCount`.

**
** 5. main(): The main function instantiates `Twitter` and `Instagram` objects
**    It tests the core functionalities:
**    - Object creation with different privacy settings.
**    - Adding followers and followed users.
**    - Displaying followers/followed based on privacy rules.
**    - Changing privacy settings.
**    - Using the derived class specific functions (`RT`, `Like`).
**    - Using getters and setters.
*************************************************************************/
#include <iostream>
#include <string>
#include <ostream> // For std::ostream
#include <utility>

// Include the header file defining the classes
#include "SocialMediaAccount.h"

// Profile struct
struct Profile {
    int userId;
    std::string username;
    // Constructor
    explicit Profile(const int id = 0, std::string name = "") : userId(id), username(std::move(name)) {}

};


int main() {

    // Twitter Account Objects
    Twitter<std::string> TS("PewPewTwitterUser");
    Twitter<Profile> TP(Profile(101, "BangBangTwitterProfile"), true); //start private
    //Insta Account Objects
    Instagram<std::string> IS("WhooshInstaUser", false); // Start public
    Instagram<Profile> IP(Profile(202, "KurplunkInstaProfile"));

    // Add followers and following
    std::cout << "--- Adding Followers/Followed ---" << std::endl;
    TS.addFollower("ImFollowingYou");
    TS.addFollowed("YouFollowedMe");
    TP.addFollower(Profile(102, "ImFollowingYourProfile"));
    TP.addFollowed(Profile(103, "YoureFollowingMyProfile"));
    IS.addFollower("InstantUserIsFollowing");
    IS.addFollowed("InstantUserIsFollowed");
    IP.addFollower(Profile(203, "InstantProfileIsFollowing"));
    IP.addFollowed(Profile(204, "InstantProfileIsFollowed"));
    std::cout << "Done adding." << std::endl << std::endl;


    // Test all the displays
    std::cout << "--- Testing Display (Check Privacy) ---" << std::endl;
    TS.displayFollowers();
    TS.displayFollowed();

    TP.displayFollowers();
    TP.displayFollowed();

    IS.displayFollowers();
    IS.displayFollowed();

    IP.displayFollowers(); // Private
    IP.displayFollowed();  // Private
    std::cout << std::endl;


    // Testing REtweets
    std::cout << "--- Testing RT() ---" << std::endl;
    std::cout << "TS Retweets: " << TS.getRetweetCount() << std::endl;
    TS.RT();
    TS.RT();
    std::cout << "TS Retweets after RT(): " << TS.getRetweetCount() << std::endl;

    std::cout << "TP Retweets: " << TP.getRetweetCount() << std::endl;
    TP.RT();
    std::cout << "TP Retweets after RT(): " << TP.getRetweetCount() << std::endl;
    std::cout << std::endl;


    // Testing Likes
    std::cout << "--- Testing Like() ---" << std::endl;
    std::cout << "IS Likes: " << IS.getLikeCount() << std::endl;
    IS.Like();
    std::cout << "IS Likes after Like(): " << IS.getLikeCount() << std::endl;

    std::cout << "IP Likes: " << IP.getLikeCount() << std::endl;
    IP.Like();
    IP.Like();
    IP.Like();
    std::cout << "IP Likes after Like(): " << IP.getLikeCount() << std::endl;
    std::cout << std::endl;


    // --- Test Setters ---
    std::cout << "--- Testing Setters ---" << std::endl;
    std::cout << "Original: " << IS.getHandler() << std::endl;
    IS.setHandler("UpdatedInstaHandle");
    std::cout << "Updated: " << IS.getHandler() << std::endl;

    std::cout << "Original TP Retweets: " << TP.getRetweetCount() << std::endl;
    TP.setRetweetCount(10);
    std::cout << "Updated TP Retweets: " << TP.getRetweetCount() << std::endl;
    std::cout << std::endl;

    return 0;
}