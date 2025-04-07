

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
** 5. main(): 
**    It tests the core functionalities:
**    - Object creation with different privacy settings.
**    - Adding followers and followed users.
**    - Displaying followers/followed based on privacy rules.
**    - Changing privacy settings.
**    - Using the derived class specific functions (`RT`, `Like`).
**    - Using getters and setters.
*************************************************************************/

#define SOCIALMEDIAACCOUNT_H

#include <iostream>
#include <string>
#include <vector> // Although using C-style arrays as requested

// Create Global Variables!
const int maxFollowers = 100; // Max size for followers array
const int maxFollowed = 150;  // Max size for followed array

struct Profile;
inline std::ostream & operator<<(std::ostream &os, const Profile &p) {}

// CLion suggestion

// don't forget the template
template <typename T>


class SocialMediaAccount {
private:
    // Private Guys
    T handler;
    T followers[maxFollowers];
    T followed[maxFollowed];
    int followerCount;
    int followedCount;
    bool privateAcc;

public:
    //Default Constructor
    SocialMediaAccount() : followerCount(0), followedCount(0), privateAcc(true) {}

    //  constructor --> the explicit was a CLion suggestion
    explicit SocialMediaAccount(const T& handlerVal, bool isPrivate = true)
        : handler(handlerVal), followerCount(0), followedCount(0), privateAcc(isPrivate) {}


    // Getters! --> [[nodiscard]] added by CLion
    T getHandler() const {return handler;}

    [[nodiscard]] int getFollowerCount() const {return followerCount;}
    [[nodiscard]] int getFollowedCount() const {return followedCount;}
    [[nodiscard]] bool isPrivate() const {return privateAcc;}

    // Setters!
    void setHandler(const T& newHandler) {handler = newHandler;}
    void setPrivate(bool isPrivate) {privateAcc = isPrivate;}


    // Add a follower
    void addFollower(const T& user) {
        if (followerCount < maxFollowers) {
            followers[followerCount] = user;
            followerCount++;
        } else {
            std::cerr << "Error"<< std::endl;
        }
    }

    // Add an account being followed
    void addFollowed(const T& user) {
        if (followedCount < maxFollowed) {
            followed[followedCount] = user;
            followedCount++;
        } else {
            std::cerr << "Error" << std::endl;
        }
    }

    // Display followers unless it's private
    void displayFollowers() const {
        if (privateAcc) {
            std::cout << "Account is protected." << std::endl;
        } else {
            if (followerCount == 0) {
                std::cout << "No followers yet." << std::endl;
            } else {
                std::cout << "Total Followers: " << followerCount << std::endl;
                for (int i = 0; i < followerCount; ++i) {
                    std::cout << "- " << followers[i] << std::endl;
                }
            }
        }
        std::cout << "-----------------------------------------" << std::endl;
    }

    // Display followed accounts unless it's private
    void displayFollowed() const {
        if (privateAcc) {
            std::cout << "Account is protected." << std::endl;
        } else {
             if (followedCount == 0) {
                std::cout << "Not following anyone yet." << std::endl;
            } else {
                std::cout << "Total Following: " << followedCount << std::endl;
                for (int i = 0; i < followedCount; ++i) {
                    // Requires T to be printable (or operator<< overloaded)
                    std::cout << "- " << followed[i] << std::endl;
                }
            }
        }
         std::cout << "-----------------------------------------" << std::endl;
    }

    // Destroy!
    virtual ~SocialMediaAccount() = default;
};


// Derived Class: Twitter
template <typename T>
class Twitter : public SocialMediaAccount<T> {
private:
    int retweetCount;

public:
    // Constructor
    Twitter() : SocialMediaAccount<T>(), retweetCount(0) {}

    Twitter(const T& handlerVal, bool isPrivate = true)
        : SocialMediaAccount<T>(handlerVal, isPrivate), retweetCount(0) {}

    // Getter
    [[nodiscard]] int getRetweetCount() const {return retweetCount;}

    // Setter
    void setRetweetCount(const int count) {retweetCount = count;}

    // RT function
    void RT() {
        retweetCount++;}
};


// Derived Class: Instagram
template <typename T>
class Instagram final : public SocialMediaAccount<T> {
private:
    int likeCount;

public:
    Instagram() : SocialMediaAccount<T>(), likeCount(0) {}

    explicit Instagram(const T& handlerVal, bool isPrivate = true)
        : SocialMediaAccount<T>(handlerVal, isPrivate), likeCount(0) {}

    // Getter
    [[nodiscard]] int getLikeCount() const {return likeCount;}

    // Setter
    void setLikeCount(const int count) {likeCount = count;}

    // Like function
    void Like() {likeCount++;}
};

