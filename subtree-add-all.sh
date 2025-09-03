#!/bin/bash

# Script to add all subtrees from .subtrees configuration file
# Usage: ./subtree-add-all.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SUBTREES_FILE="$SCRIPT_DIR/.subtrees"

if [[ ! -f "$SUBTREES_FILE" ]]; then
    echo "Error: .subtrees file not found at $SUBTREES_FILE"
    exit 1
fi

echo "Adding all subtrees from .subtrees configuration..."
echo

# Read each line from .subtrees file
while IFS=':' read -r prefix repo_url branch || [[ -n "$prefix" ]]; do
    # Skip empty lines and comments
    if [[ -z "$prefix" || "$prefix" =~ ^[[:space:]]*# ]]; then
        continue
    fi
    
    # Trim whitespace
    prefix=$(echo "$prefix" | tr -d ' ')
    repo_url=$(echo "$repo_url" | tr -d ' ')
    branch=$(echo "$branch" | tr -d ' ')
    
    echo "Adding subtree: $prefix from $repo_url ($branch)"
    
    # Check if directory already exists
    if [[ -d "$prefix" ]]; then
        echo "  Directory $prefix already exists, skipping..."
        echo
        continue
    fi
    
    # Add subtree
    if git subtree add --prefix="$prefix" "$repo_url" "$branch" --squash; then
        echo "  ✅ Successfully added $prefix"
    else
        echo "  ❌ Failed to add $prefix"
        exit 1
    fi
    echo
done < "$SUBTREES_FILE"

echo "All subtrees have been added successfully!"
