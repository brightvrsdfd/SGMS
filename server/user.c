#include "user.h"

// Define user list as a global variable
user_t *user_list = NULL;

// Validate user
// Parameters: username, password
// Return: 1 if valid, 0 if invalid
int validate_user(char *username, char *password) {
    // Loop through the user list
    for (user_t *user = user_list; user != NULL; user = user->next) {
        // Compare the username and password
        if (strcmp(user->username, username) == 0 && strcmp(user->password, password) == 0) {
            // Return 1 if matched
            return 1;
        }
    }
    // Return 0 if not matched
    return 0;
}

// Add user
// Parameters: username, password
// Return: 1 if success, 0 if failure
int add_user(char *username, char *password) {
    // Check if the username already exists
    if (find_user(username) != NULL) {
        // Return 0 if exists
        return 0;
    }
    // Allocate memory for a new user
    user_t *user = malloc(sizeof(user_t));
    if (user == NULL) {
        perror("malloc");
        return 0;
    }
    // Copy the username and password
    strcpy(user->username, username);
    strcpy(user->password, password);
    // Initialize the file list and the snapshot list
    user->file_list = NULL;
    user->snapshot_list = NULL;
    // Insert the user to the front of the user list
    user->next = user_list;
    user_list = user;
    // Return 1 if success
    return 1;
}

// Delete user
// Parameters: username
// Return: 1 if success, 0 if failure
int delete_user(char *username) {
    // Find the user and its previous user
    user_t *user = find_user(username);
    user_t *prev = find_prev_user(username);
    if (user == NULL) {
        // Return 0 if not found
        return 0;
    }
    // Delete all the files and snapshots of the user
    delete_all_files(user);
    delete_all_snapshots(user);
    // Remove the user from the user list
    if (prev == NULL) {
        // If the user is the first one, update the user list head
        user_list = user->next;
    } else {
        // If the user is not the first one, update the previous user's next pointer
        prev->next = user->next;
    }
    // Free the memory of the user
    free(user);
    // Return 1 if success
    return 1;
}

// Find user
// Parameters: username
// Return: user pointer if found, NULL if not found
user_t *find_user(char *username) {
    // Loop through the user list
    for (user_t *user = user_list; user != NULL; user = user->next) {
        // Compare the username
        if (strcmp(user->username, username) == 0) {
            // Return the user pointer if matched
            return user;
        }
    }
    // Return NULL if not matched
    return NULL;
}

// Find previous user
// Parameters: username
// Return: previous user pointer if found, NULL if not found or the first one
user_t *find_prev_user(char *username) {
    // Initialize the previous user pointer to NULL
    user_t *prev = NULL;
    // Loop through the user list
    for (user_t *user = user_list; user != NULL; user = user->next) {
        // Compare the username
        if (strcmp(user->username, username) == 0) {
            // Return the previous user pointer if matched
            return prev;
        }
        // Update the previous user pointer
        prev = user;
    }
    // Return NULL if not matched
    return NULL;
}

// Modify user
// Parameters: username, new password
// Return: 1 if success, 0 if failure
int modify_user(char *username, char *new_password) {
    // Find the user
    user_t *user = find_user(username);
    if (user == NULL) {
        // Return 0 if not found
        return 0;
    }
    // Copy the new password
    strcpy(user->password, new_password);
    // Return 1 if success
    return 1;
}

// Display user
// Parameters: username
// Return: 1 if success, 0 if failure
int display_user(char *username) {
    // Find the user
    user_t *user = find_user(username);
    if (user == NULL) {
        // Return 0 if not found
        return 0;
    }
    // Print the user information
    printf("Username: %s\n", user->username);
    printf("Password: %s\n", user->password);
    // Return 1 if success
    return 1;
}
