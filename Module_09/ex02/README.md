# README.md

## **Ford-Johnson Merge-Insertion Algorithm**

This project implements the Ford-Johnson Merge-Insertion sorting algorithm, a comparison-based sorting algorithm that minimizes the number of pairwise comparisons required to sort a sequence. The algorithm is particularly efficient for small $$ n $$ and leverages the Jacobsthal sequence to optimize insertion order.

---

## **Overview**

### **Algorithm Description**
The Ford-Johnson algorithm combines elements of merge sort and insertion sort:
1. **Pairing:** Divide the sequence into pairs and sort each pair.
2. **Main Chain:** Sort the larger elements of each pair recursively to form a "main chain."
3. **Pend Elements:** Insert the smaller elements (pend) into the main chain using binary search, following an order dictated by Jacobsthal numbers.

### **Key Features**
- Minimizes the number of comparisons in the worst case.
- Utilizes Jacobsthal numbers to optimize insertion order.
- Suitable for scenarios where comparison cost is high relative to computational overhead.

---

## **Step-by-Step Recipe**

### **Ford-Johnson Algorithm**
1. **Input:** An unsorted sequence $$ X $$ of $$ n $$ elements.
2. **Pairing:**
   - Group $$ X $$ into $$ \lfloor n/2 \rfloor $$ pairs.
   - Leave one element unpaired if $$ n $$ is odd.
   - Sort each pair with one comparison, resulting in pairs $$[a, b]$$, where $$ a  1
\end{cases}
$$

### **Sequence**
The first few Jacobsthal numbers are:
$$ 
0, 1, 1, 3, 5, 11, 21, 43, ...
$$

### **Closed-Form Formula**
Jacobsthal numbers can also be calculated directly:
$$
J_n = \frac{2^n - (-1)^n}{3}
$$

### **Application in Ford-Johnson Algorithm**
Jacobsthal numbers dictate the order in which pend elements are inserted into the main chain:
- For example: For pend size $$ n = 6 $$, use indices derived from Jacobsthal progression: `0 → 1 → 3 → ...`.

---

## **Project Structure**

### Files
- `main.cpp`: Entry point of the program.
- `PmergeMe.cpp`: Implementation of Ford-Johnson algorithm and helper functions.
- `Logger.cpp`: Logging utilities for debugging and performance tracking.
- `Ansi.h`: ANSI escape codes for colored terminal output.

### Key Functions
- `mergeInsertVector()`: Performs merge-insertion sort on a vector.
- `mergeInsertList()`: Performs merge-insertion sort on a list.
- `jacobsthalGenerator()`: Generates Jacobsthal numbers recursively or via memoization.

---

## **How to Run**

1. Compile the program using a C++ compiler:
   ```bash
   g++ -std=c++98 -o PmergeMe main.cpp PmergeMe.cpp Logger.cpp
   ```

2. Run with input sequences:
   ```bash
   ./PmergeMe "3 5 9 7 4"
   ```

3. Example Output:
   ```
   Before: 3 5 9 7 4
   After: 3 4 5 7 9
   Time to process a range of X elements with std::vector : Y us
   Time to process a range of X elements with std::list : Z us
   ```

---

## **References**

1. Ford-Johnson Algorithm (1959): Minimizing pairwise comparisons for sorting.
2. Jacobsthal Numbers (Ernst Jacobsthal): Recurrence-based integer sequence used for insertion ordering.

For more details on Merge-Insertion Sort and Jacobsthal numbers:
- [Wikipedia on Merge-Insertion Sort](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Wikipedia on Jacobsthal Numbers](https://en.wikipedia.org/wiki/Jacobsthal_number)

--- 

This README provides all necessary information for understanding and running the project effectively!

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/6e44bb62-81e6-4283-b396-049de431d2ec/main.cpp
[2] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/0e9f7783-e646-4f50-9de2-e62be1d705f6/printer.cpp
[3] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/0bd2c989-f65c-4b13-8adb-247e06785046/PmergeMe.cpp
[4] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/15f13af5-bc67-4695-978b-5cc90eda7f25/Logger.cpp
[5] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/3c68e467-1980-4106-9d08-de24bc4664ca/Ansi.h
[6] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/3eb62bbe-c3e5-459f-9ea7-2c72cf17817a/PmergeMe.hpp
[7] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/014efed5-45ab-4fce-bcf5-99050c485416/Logger.hpp
[8] https://www.semanticscholar.org/paper/073b31849da06603fa5a37cba31231623e8e7bdb
[9] https://www.semanticscholar.org/paper/539ad1fc97965312b09d7ae956ceda5054213e44
[10] https://arxiv.org/abs/1905.09656
[11] https://en.wikipedia.org/wiki/Jacobsthal_number
[12] https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
[13] https://www.tutorialspoint.com/jacobsthal-and-jacobsthal-lucas-numbers
[14] https://en.wikipedia.org/wiki/Merge-insertion_sort
[15] https://www.semanticscholar.org/paper/cc45cc1f280ccbe3cfee42370faa1f4ce9b2f9f5
[16] https://www.semanticscholar.org/paper/03b9f9bd38a37d3dfeea3a0bdc41fac15c64edcc
[17] https://www.semanticscholar.org/paper/bb5f72edab4f2035eb6f57ea2f090c8f1e4dde82
[18] https://www.semanticscholar.org/paper/a59bc979acb728f6880e409b735c7119fe55c010
[19] https://www.reddit.com/r/algorithms/comments/1bajgye/merge_insertion_ford_johnson/?tl=nl
[20] https://www.reddit.com/r/algorithms/comments/1gkwrsy/help_needed_choosing_a_topic_for_my_seminar_paper/
[21] https://www.reddit.com/r/learnprogramming/comments/roo3vm/why_is_mergesort_faster_than_insertion_sort_when/
[22] https://www.reddit.com/r/compsci/comments/2r7e5w/i_want_to_know_how_merge_insertion_works_can/
[23] https://www.reddit.com/r/learnprogramming/comments/rol90y/are_selection_and_insertion_sort_ever_used_as/
[24] https://www.reddit.com/r/coding/comments/1e5kjmc/the_gilbertjohnsonkeerthi_algorithm_explained_as/
[25] https://www.reddit.com/r/learnprogramming/comments/ik384g/time_complexity_comparing_insertion_sort_and/
[26] https://www.w3resource.com/python-exercises/data-structures-and-algorithms/python-search-and-sorting-exercise-39.php
[27] https://dl.acm.org/doi/pdf/10.1145/322139.322145
[28] https://stackoverflow.com/questions/27751132/how-does-merge-insertion-sort-work
[29] https://arxiv.org/pdf/1905.09656.pdf
[30] https://www.semanticscholar.org/paper/463a5c37a37fb71924b3b1afbe413f907ac451ff
[31] https://www.semanticscholar.org/paper/cbeb9cfb275e0919b3c176894e13b0e983528dbc
[32] https://www.semanticscholar.org/paper/2b56db77cb56add8bc7c133e050d292366309e49
[33] https://www.semanticscholar.org/paper/de1361e5c9c9d82ee260ee57f849e27256d3701c
[34] https://www.reddit.com/r/math/comments/i8zf6s/a_fun_sequence_i_came_across/
[35] https://www.reddit.com/r/math/comments/72mqpx/prime_number_gaps_jacobsthal_function_applied_to/
[36] https://www.reddit.com/r/Collatz/comments/1egurvb/a_significant_collatz_paper/
[37] https://www.reddit.com/r/Collatz/comments/1c99fav/proof_attempt_for_collatz_conjecture_at/
[38] https://www.reddit.com/r/teachingresources/comments/1cfdyqt/need_a_refresher_on_finding_terms_of_a_geometric/
[39] https://www.reddit.com/r/Collatz/comments/1g2ftqg/what_if_we_have_been_looking_at_the_wrong_thing/
[40] https://www.reddit.com/r/AdvancedMathematics/rising/
[41] https://www.reddit.com/r/3Blue1Brown/comments/mllj2s/topic_requests/
[42] https://www.reddit.com/r/numbertheory/comments/1d5ivml/the_relationship_between_3n1_and_5n1_conjecture/
[43] https://www.reddit.com/r/learnprogramming/comments/1eixd3g/little_question_to_know_better_the_fordjohnson/
[44] https://www.reddit.com/r/javahelp/comments/qw63gh/recursive_to_iterative_to_save_memory/
[45] http://arxiv.org/pdf/1611.03310.pdf
[46] https://oeis.org/A001045
[47] https://arxiv.org/abs/1611.03310
[48] https://stackoverflow.com/questions/70032113/jacobsthal-number-recursion-formula
[49] https://arxiv.org/abs/1911.11515
[50] https://onlinelibrary.wiley.com/doi/10.1155/2021/2888840
[51] http://arxiv.org/pdf/1903.11973.pdf
[52] https://www.fq.math.ca/Scanned/34-1/horadam2.pdf
[53] https://mathworld.wolfram.com/JacobsthalNumber.html
[54] https://www.montis.pmf.ac.me/allissues/57/Mathematica-Montisnigri-57-4.pdf
[55] https://www.tandfonline.com/doi/pdf/10.1080/07468342.2023.2282201
[56] https://www.semanticscholar.org/paper/2f26314b3aa5e130f3b36a117c4b3adb5d77470f
[57] https://www.semanticscholar.org/paper/56ef4099347b4481d7e94927a8916049b3e18677
[58] https://www.semanticscholar.org/paper/f65d7ca9a81751851d8e4a684127cafe52581fae
[59] https://pubmed.ncbi.nlm.nih.gov/26218060/
[60] https://www.reddit.com/r/learnprogramming/comments/1eft41i/issues_with_the_fordjohnson_algorithm/
[61] https://www.reddit.com/r/math/comments/1d1ojy1/are_there_any_integer_sequences_known_to_be/
[62] https://www.reddit.com/r/algorithms/comments/pd49yh/hybrid_insertion_and_merge_sort/
[63] https://www.reddit.com/r/algorithms/comments/1bajgye/merge_insertion_ford_johnson/
[64] https://www.reddit.com/r/learnprogramming/comments/1bajhlq/does_the_mergeinsertion_sort_fordjohnson/
[65] https://www.reddit.com/r/algorithms/comments/11x3rkh/step_3_of_mergeinsertion_sort_confuses_me_on/
[66] https://github.com/decidedlyso/merge-insertion-sort
[67] https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
[68] https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
[69] https://www.semanticscholar.org/paper/19e6f9cb3389577e8c4a3382f2e4aa1ac06e2854
[70] https://www.semanticscholar.org/paper/7190b31c1a0eae052e878e3bbcb1c71ce93eda50
[71] https://www.semanticscholar.org/paper/0b48b206e33b1f434cefadc5cb26768047edae86
[72] https://arxiv.org/abs/2306.14635
[73] https://www.semanticscholar.org/paper/27ceede673890932499f5248a1410c881b617743
[74] https://www.reddit.com/r/Collatz/comments/1be3wdl/attempted_proof/
[75] https://internationalpubls.com/index.php/cana/article/download/1037/725/1913
[76] https://nntdm.net/papers/nntdm-24/NNTDM-24-1-120-135.pdf
[77] https://rosettacode.org/wiki/Jacobsthal_numbers
[78] https://planetmath.org/jacobsthalsequence
