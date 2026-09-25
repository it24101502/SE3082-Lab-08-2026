# SE4060 – Parallel Computing
## Lab Sheet 6 – MPI

**Program:** BSc (Hons) in Information Technology Year 4  
**Module:** SE4060 – Parallel Computing  
**Semester:** Semester 2, 2021

---

# Objectives

- Write MPI programs

---

# Exercise 0

Complete the in-class MPI activities provided in the following repository:

https://github.com/SLIITFacultyOfComputing/SE4060-MPI-Part1

---

# Exercise 1

- Create a GitHub repository with your student ID.
- If you already have one, you may use it.
- Log in to your GitHub account.
- Complete the exercises provided in the repository.
- Commit and push your solutions to GitHub.

---

# Exercise 2

Parallelize adding up numbers from **1 to 10,000,000** using multiple nodes with MPI.

---

# Exercise 3

Parallelize the computation of **Pi** using the **Monte Carlo Method** with MPI.

Reference:

http://www.dartmouth.edu/~rc/classes/soft_dev/C_simple_ex.html

Requirements:

- Use MPI for parallelization.
- Perform the calculation **10,000,000 times**.

---

# Exercise 4

For both **Exercise 1** and **Exercise 2**:

1. Plot a graph showing:

   ```text
   Time vs Number of Processors
   ```

2. Plot a graph showing:

   ```text
   Speedup vs Number of Processors
   ```

---

# Exercise 5

## Part 1

Write a simple program where the source and destination do not match.

You may modify either:

- `message1.cc`
- `message2.cc`

Observe and explain what happens.

---

## Part 2

Rewrite `message2.cc` using **Buffered Send (MPI_Bsend)**.

Requirements:

- Do not replace the variables used for sending data.
- Use MPI buffered communication.

---

# Exercise 6

Rewrite Exercise 3 by changing the receiving tag to:

```cpp
MPI_ANY_SOURCE
```

Redo Exercise 3 and compare the results with the original implementation.

---

# Exercise 7

Rewrite Exercise 6 using:

```cpp
MPI_Bsend
```

Requirements:

- Use Buffered Send (BSend).
- Compare the results with Exercise 6.

---

# Submission

- Push all exercises to your GitHub repository.
- Include source code.
- Include execution output.
- Include required graphs and screenshots.
- Ensure all exercises are committed and pushed successfully.