#define TABLE_SIZE 10007  // A prime number for better hashing

// Hash set node
typedef struct HashNode {
    int key;
    bool is_occupied;
} HashNode;

HashNode hash_table[TABLE_SIZE];

// Simple hash function
int hash(int key) {
    if (key < 0) key = -key;  // Make sure we handle negative numbers
    return key % TABLE_SIZE;
}

// Insert into hash set
void insert(int key) {
    int index = hash(key);
    while (hash_table[index].is_occupied && hash_table[index].key != key) {
        index = (index + 1) % TABLE_SIZE;  // Linear probing
    }
    hash_table[index].key = key;
    hash_table[index].is_occupied = true;
}

// Search in hash set
bool exists(int key) {
    int index = hash(key);
    int start = index;
    while (hash_table[index].is_occupied) {
        if (hash_table[index].key == key)
            return true;
        index = (index + 1) % TABLE_SIZE;  // Linear probing
        if (index == start) break; // Full loop
    }
    return false;
}

// O(n) Longest Consecutive Sequence
int longestConsecutive(int *arr, int n) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].is_occupied = false;
    }
    // Insert all elements into the hash set, ensuring no duplicates
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }

    int maxLen = 0;

    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        int num = arr[i];

        // Check if num is the start of a sequence
        if (!exists(num - 1)) {
            int curr = num;
            int count = 1;

            // Count the length of the sequence starting from num
            while (exists(curr + 1)) {
                curr++;
                count++;
            }

            // Update max length
            if (count > maxLen) {
                maxLen = count;
            }
        }
    }

    return maxLen;
}
