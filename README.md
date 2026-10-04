# Smart Delivery Planning

A **Package Optimization System** using the **Fractional Knapsack Algorithm** in C.

**Fractional Knapsack | Greedy Algorithm | Menu-Driven | Package Optimization**

## About the Project

The **Smart Delivery Planning** system is a console-based C application that helps select packages efficiently based on a vehicle's carrying capacity.

It uses the **Fractional Knapsack algorithm**, where packages are selected according to their **Value/Weight ratio**. Packages with higher ratios are prioritized to maximize the total value.

If the remaining vehicle capacity is insufficient for a complete package, a **fraction of that package** is selected.

---

## Features

| **Feature**                   | **Description**                         |
| ----------------------------- | --------------------------------------- |
| **Enter Package Details**     | Add package value and weight            |
| **Display Package Details**   | View all entered packages               |
| **Calculate Ratio**           | Calculate Value/Weight ratio            |
| **Sort Packages**             | Sort packages by decreasing ratio       |
| **Find Maximum Value**        | Calculate maximum value within capacity |
| **Display Selected Packages** | Show selected packages and fractions    |
| **Menu Driven**               | Easy console-based interaction          |

---

## Tech Stack

```text
+------------------+------------------------+------------------+
|   Programming    |     Algorithm          |    Approach      |
+------------------+------------------------+------------------+
|        C         | Fractional Knapsack    |  Menu Driven     |
|    Language      |     Greedy Method      |  Step-by-Step    |
+------------------+------------------------+------------------+
```

* **Language**: C
* **Compiler/IDE**: Dev-C++
* **Algorithm**: Fractional Knapsack
* **Approach**: Greedy Algorithm
* **Data Structure**: Structure Array

---

## Data Structure Used

### Structure

Each package is stored using a `struct Package` containing:

```text
┌────────────┬──────────────┬──────────────┬──────────────┬────────────┐
│ packageNo  │ value        │ weight       │ ratio        │ fraction   │
├────────────┼──────────────┼──────────────┼──────────────┼────────────┤
│ int        │ float        │ float        │ float        │ float      │
└────────────┴──────────────┴──────────────┴──────────────┴────────────┘
```

The program can store up to **100 packages**.

---

## Key Concepts Applied

* **Fractional Knapsack Algorithm**
* **Greedy Approach**
* **Value/Weight Ratio**
* **Sorting**
* **Structures in C**
* **Arrays**
* **Menu-Driven Programming**
* **Fractional Package Selection**

---

## Input Flow

```text
              ┌─────────────────────────┐
              │      ENTER DETAILS      │
              └────────────┬────────────┘
                           │
                           ▼
                 Number of Packages
                           │
                           ▼
                  Vehicle Capacity
                           │
                           ▼
              ┌─────────────────────────┐
              │ For Each Package       │
              │ • Package Value        │
              │ • Package Weight       │
              └────────────┬────────────┘
                           │
                           ▼
                 Calculate Value/Weight
                           │
                           ▼
                  Sort by Ratio
                           │
                           ▼
              Select Full/Fractional
                   Packages
                           │
                           ▼
              Maximum Value & Weight
```

---

## Installation & Usage (Dev-C++)

### Step 1: Open Dev-C++

Create a new **C source file**.

### Step 2: Write Code

Copy the Smart Delivery Planning program into the editor.

### Step 3: Compile & Run

Press **F11** or select **Compile & Run**.

### Step 4: Enter Details

Select the required option from the menu and enter package information.

---

## Sample Input

```text
============================================
       SMART DELIVERY PLANNING
       FRACTIONAL KNAPSACK
============================================
1. Enter Package Details
2. Display Package Details
3. Calculate Value/Weight Ratio
4. Sort Packages by Ratio
5. Find Maximum Value
6. Display Selected Packages
7. Exit

Enter your choice: 1

Enter number of packages: 3
Enter vehicle capacity: 50

Package 1
Enter value: 100
Enter weight: 20

Package 2
Enter value: 120
Enter weight: 30

Package 3
Enter value: 150
Enter weight: 40
```

---

## Sample Output

```text
============================================
        SELECTED PACKAGES
============================================

Package    Value      Weight     Ratio        Fraction
1          100.00     20.00      5.00         1.00
2          120.00     30.00      4.00         1.00

Vehicle capacity = 50.00
Total weight     = 50.00
Maximum value    = 220.00
```

---

## Project Workflow

```text
                 ┌───────────────────────────┐
                 │        MAIN MENU           │
                 │ 1-Enter Details            │
                 │ 2-Display Details          │
                 │ 3-Calculate Ratio         │
                 │ 4-Sort Packages            │
                 │ 5-Find Maximum Value       │
                 │ 6-Display Selected         │
                 │ 7-Exit                     │
                 └─────────────┬─────────────┘
                               │
             ┌─────────────────┼─────────────────┐
             ▼                 ▼                 ▼
       ┌────────────┐   ┌────────────┐   ┌────────────┐
       │  ENTER     │   │ CALCULATE  │   │   SORT     │
       │  DETAILS   │   │   RATIO    │   │ PACKAGES   │
       └─────┬──────┘   └─────┬──────┘   └─────┬──────┘
             │                │                 │
             └────────────────┼─────────────────┘
                              ▼
                    ┌──────────────────┐
                    │ SELECT PACKAGES  │
                    │ Full/Fractional  │
                    └────────┬─────────┘
                             │
                             ▼
                    ┌──────────────────┐
                    │ MAXIMUM VALUE    │
                    │ & TOTAL WEIGHT   │
                    └──────────────────┘
```

## Algorithm

1. Read package details and vehicle capacity.
2. Calculate the Value/Weight ratio for each package.
3. Sort packages in decreasing order of ratio.
4. Select packages with the highest ratio first.
5. If capacity is insufficient, select the required fraction.
6. Calculate total weight and maximum value.
7. Display the selected packages.
