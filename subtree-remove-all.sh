#!/bin/bash

# Script to remove all subtrees from .subtrees configuration file
# Usage: ./subtree-remove-all.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SUBTREES_FILE="$SCRIPT_DIR/.subtrees"

if [[ ! -f "$SUBTREES_FILE" ]]; then
    echo "Error: .subtrees file not found at $SUBTREES_FILE"
    exit 1
fi

echo "WARNING: This will remove all subtree directories and their git history!"
read -p "Are you sure you want to continue? (y/N): " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Yy]$ ]]; then
    echo "Operation cancelled."
    exit 0
fi

echo "Removing all subtrees from .subtrees configuration..."
echo

# Read each line from .subtrees file
while IFS=':' read -r prefix repo_url branch || [[ -n "$prefix" ]]; do
    # Skip empty lines and comments
    if [[ -z "$prefix" || "$prefix" =~ ^[[:space:]]*# ]]; then
        continue
    fi
    
    # Trim whitespace
    prefix=$(echo "$prefix" | tr -d ' ')
    
    echo "Removing subtree: $prefix"
    
    # Check if directory exists
    if [[ ! -d "$prefix" ]]; then
        echo "  Directory $prefix does not exist, skipping..."
        echo
        continue
    fi
    
    # Remove from git and filesystem
    if git rm -r "$prefix"; then
        echo "  ✅ Successfully removed $prefix"
    else
        echo "  ❌ Failed to remove $prefix"
        exit 1
    fi
    echo
done < "$SUBTREES_FILE"

echo "All subtrees have been removed successfully!"
echo "Don't forget to commit the changes: git commit -m 'Remove all subtrees'"
