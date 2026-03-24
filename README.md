This activity has been created as part of the 42 curriculum by aal-moum, atahtamo.

🚀 Push Swap

📌 Description
    Push Swap is a project from the 42 curriculum that focuses on sorting a list of integers using two stacks (a and b) and a limited set of operations.
    The goal is to sort the input in ascending order while minimizing the number of operations performed.

This project emphasizes:
    Algorithmic thinking
    Optimization
    Data structures (linked lists / stacks)
    Complexity analysis

⚙️ Instructions
    🔨 Compilation
        make

    🧹 Cleaning
        make clean     # remove object files
        make fclean    # remove executable
        make re        # rebuild project

    ▶️ Execution
        ./push_swap [numbers...]
        
        Examples
            ./push_swap 3 2 1
            ./push_swap "3 2 1"
            ./push_swap "1 2" 3

📊 Benchmark Mode
    ./push_swap --bench 3 2 1
    Displays:
        disorder percentage
        selected strategy
        operation count

🧠 Algorithm Choices & Justification
    This implementation uses multiple sorting strategies and selects the most appropriate one based on the input.
    🔹 1. Simple Sort (O(n²))
        Used for:
            Small inputs
            Nearly sorted data
        
        Approach:
            Repeatedly find the minimum value
            Move it to stack b
            Rebuild stack a
        
        Justification:
            Efficient for small datasets
            Minimal overhead
            Performs well when disorder is low

    🔹 2. Medium Sort – Chunk-Based (O(n√n))
        Used for:
            Medium-sized inputs
        
        Approach:
            Normalize values (indexing)
            Divide input into chunks
            Push elements to stack b in ranges
            Rebuild stack a by pushing back the maximum
        
        Justification:
            Reduces unnecessary rotations
            Efficient compromise between complexity and operations
            Common optimization for push_swap

    🔹 3. Complex Sort – Radix Sort (O(n log n))
        Used for:
            Large datasets
        
        Approach:
            Convert values to indices
            Sort using binary representation
            Push based on bit values
            Rebuild stack after each iteration
        
        Justification:
            Very efficient for large inputs
            Predictable performance
            Widely used optimal solution for push_swap

    🔹 4. Adaptive Strategy
        The program computes a disorder ratio:
            disorder = misplaced_pairs / total_pairs
        
        Based on this:
            Disorder	Strategy
             < 20%	     Simple
             < 50%       Medium
             ≥ 50%	     Complex
        
        Justification:
            Avoids using heavy algorithms unnecessarily
            Improves performance on partially sorted inputs
            Provides dynamic optimization

🛡️ Error Handling
    The program handles:
        Invalid characters
        Overflow / underflow
        Duplicate numbers
        Empty input
        Incorrect formatting
    Outputs:
        Error

📈 Performance
    Input Size	  Operations
        100         ~555
        500	        ~5380
    Within the required limits for evaluation.

📚 Resources
📖 References
    42 Subject (Push Swap)
    Stack data structure documentation
    Radix sort algorithm
    Fisher–Yates shuffle (for testing)
    Complexity analysis resources

🤖 AI Usage
    AI tools (such as ChatGPT) were used for:
        Code review and debugging assistance
        Understanding algorithm optimizations
        Clarifying theoretical concepts
        Improving documentation quality
    All implementation and logic decisions were written and validated manually.
