#!/bin/bash

# Script to update all subtrees from .subtrees configuration file
# Usage: ./subtree-update-all.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SUBTREES_FILE="$SCRIPT_DIR/.subtrees"

if [[ ! -f "$SUBTREES_FILE" ]]; then
    echo "Error: .subtrees file not found at $SUBTREES_FILE"
    exit 1
fi

echo "Updating all subtrees from .subtrees configuration..."
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
    
    echo "Updating subtree: $prefix from $repo_url ($branch)"
    
    # Check if directory exists
    if [[ ! -d "$prefix" ]]; then
        echo "  Directory $prefix does not exist. Use subtree-add-all.sh first."
        echo
        continue
    fi
    
    # Update subtree
    if git subtree pull --prefix="$prefix" "$repo_url" "$branch" --squash; then
        echo "  ✅ Successfully updated $prefix"
    else
        echo "  ❌ Failed to update $prefix"
        # Continue with other subtrees even if one fails
    fi
    echo
done < "$SUBTREES_FILE"

echo "Subtree update process completed!"
