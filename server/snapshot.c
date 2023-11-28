
#include "snapshot.h"

// Create snapshot
// Parameters: user pointer, snapshot name
// Return: 1 if success, 0 if failure
int create_snapshot(user_t *user, char *snapshot_name) {
    // Check if the snapshot name already exists
    if (find_snapshot(user, snapshot_name) != NULL) {
        // Return 0 if exists
        return 0;
    }
    // Allocate memory for a new snapshot
    snapshot_t *snapshot = malloc(sizeof(snapshot_t));
    if (snapshot == NULL) {
        perror("malloc");
        return 0;
    }
    // Copy the snapshot name
    strcpy(snapshot->name, snapshot_name);
    // Initialize the file list
    snapshot->file_list = NULL;
    // Loop through the user's file list
    for (file_t *file = user->file_list; file != NULL; file = file->next) {
        // Copy the file information
        file_t *file_copy = copy_file(file);
        if (file_copy == NULL) {
            // Free the memory of the snapshot and its file list
            delete_all_files(snapshot);
            free(snapshot);
            return 0;
        }
        // Insert the file copy to the front of the snapshot's file list
        file_copy->next = snapshot->file_list;
        snapshot->file_list = file_copy;
    }
    // Insert the snapshot to the front of the user's snapshot list
    snapshot->next = user->snapshot_list;
    user->snapshot_list = snapshot;
    // Return 1 if success
    return 1;
}

// Delete snapshot
// Parameters: user pointer, snapshot name
// Return: 1 if success, 0 if failure
int delete_snapshot(user_t *user, char *snapshot_name) {
    // Find the snapshot and its previous snapshot
    snapshot_t *snapshot = find_snapshot(user, snapshot_name);
    snapshot_t *prev = find_prev_snapshot(user, snapshot_name);
    if (snapshot == NULL) {
        // Return 0 if not found
        return 0;
    }
    // Delete all the files of the snapshot
    delete_all_files(snapshot);
    // Remove the snapshot from the user's snapshot list
    if (prev == NULL) {
        // If the snapshot is the first one, update the user's snapshot list head
        user->snapshot_list = snapshot->next;
    } else {
        // If the snapshot is not the first one, update the previous snapshot's next pointer
        prev->next = snapshot->next;
    }
    // Free the memory of the snapshot
    free(snapshot);
    // Return 1 if success
    return 1;
}

// Find snapshot
// Parameters: user pointer, snapshot name
// Return: snapshot pointer if found, NULL if not found
snapshot_t *find_snapshot(user_t *user, char *snapshot_name) {
    // Loop through the user's snapshot list
    for (snapshot_t *snapshot = user->snapshot_list; snapshot != NULL; snapshot = snapshot->next) {
        // Compare the snapshot name
        if (strcmp(snapshot->name, snapshot_name) == 0) {
            // Return the snapshot pointer if matched
            return snapshot;
        }
    }
    // Return NULL if not matched
    return NULL;
}

// Find previous snapshot
// Parameters: user pointer, snapshot name
// Return: previous snapshot pointer if found, NULL if not found or the first one
snapshot_t *find_prev_snapshot(user_t *user, char *snapshot_name) {
    // Initialize the previous snapshot pointer to NULL
    snapshot_t *prev = NULL;
    // Loop through the user's snapshot list
    for (snapshot_t *snapshot = user->snapshot_list; snapshot != NULL; snapshot = snapshot->next) {
        // Compare the snapshot name
        if (strcmp(snapshot->name, snapshot_name) == 0) {
            // Return the previous snapshot pointer if matched
            return prev;
        }
        // Update the previous snapshot pointer
        prev = snapshot;
    }
    // Return NULL if not matched
    return NULL;
}

// Restore snapshot
// Parameters: user pointer, snapshot name
// Return: 1 if success, 0 if failure
int restore_snapshot(user_t *user, char *snapshot_name) {
    // Find the snapshot
    snapshot_t *snapshot = find_snapshot(user, snapshot_name);
    if (snapshot == NULL) {
        // Return 0 if not found
        return 0;
    }
    // Delete all the files of the user
    delete_all_files(user);
    // Loop through the snapshot's file list
    for (file_t *file = snapshot->file_list; file != NULL; file = file->next) {
        // Copy the file information
        file_t *file_copy = copy_file(file);
        if (file_copy == NULL) {
            // Delete all the files of the user
            delete_all_files(user);
            return 0;
        }
        // Insert the file copy to the front of the user's file list
        file_copy->next = user->file_list;
        user->file_list = file_copy;
    }
    // Return 1 if success
    return 1;
}

// Display snapshot
// Parameters: user pointer, snapshot name
// Return: 1 if success, 0 if failure
int display_snapshot(user_t *user, char *snapshot_name) {
    // Find the snapshot
    snapshot_t *snapshot = find_snapshot(user, snapshot_name);
    if (snapshot == NULL) {
        // Return 0 if not found
        return 0;
    }
    // Print the snapshot information
    printf("Snapshot name: %s\n", snapshot->name);
    printf("File list:\n");
    // Loop through the snapshot's file list
    for (file_t *file = snapshot->file_list; file != NULL; file = file->next) {
        // Print the file information
        printf("File name: %s\n", file->name);
        printf("File size: %ld\n", file->size);
        printf("File content: %s\n", file->content);
    }
    // Return 1 if success
    return 1;
}
