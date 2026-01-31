# Assignment Repository

This repository contains academic assignments and projects focused on algorithms, machine learning, and automated testing.

## 📁 Repository Structure

```
Assignment/
├── code/              # Source code files
│   ├── *.cpp         # C++ implementations
│   └── *.ipynb       # Jupyter notebooks
├── datasets/         # Data files for assignments
│   ├── *.csv         # CSV datasets
│   └── *.txt         # Text data files
└── docs/             # Documentation and study guides
    ├── *.md          # Markdown documentation
    └── *.tex         # LaTeX documents
```

## 📚 Assignments Overview

### 1. A* Pathfinding Algorithm (012230028.ipynb)
**Description:** Implementation of the A* (A-star) pathfinding algorithm for finding optimal paths in graphs.

**Key Features:**
- Graph representation with coordinates and adjacency lists
- Heuristic function using Euclidean distance
- Node state management
- Optimal path finding with cost calculation

**Input Files:**
- `datasets/1.txt` - Node coordinates (format: NodeName X Y)
- `datasets/2.txt` - Edge connections (format: Node1 Node2 Cost)

**How to Run:**
1. Ensure you have the required input files in the `datasets/` folder
2. Run the Jupyter notebook
3. Input the number of nodes and connections when prompted
4. View the solution path and total cost

---

### 2. KNN Classification (knnClassification.ipynb)
**Description:** K-Nearest Neighbors classification implementation on the Iris dataset.

**Dataset:** Iris.csv
- **Features:** Sepal Length, Sepal Width, Petal Length, Petal Width
- **Target:** Species classification (Iris-setosa, Iris-versicolor, Iris-virginica)
- **Total Samples:** 150

**Data Split:**
- Training: 70%
- Validation: 15%
- Testing: 15%

**How to Run:**
1. Ensure `datasets/Iris.csv` is available
2. Update the notebook path: `data_path = '../datasets/Iris.csv'`
3. Run all cells in the notebook
4. Evaluate classification accuracy on test set

---

### 3. KNN Regression (KnnRegression.ipynb)
**Description:** K-Nearest Neighbors regression implementation on the Diabetes dataset.

**Dataset:** diabetes.csv
- **Features:** Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin, BMI, DiabetesPedigreeFunction, Age
- **Target:** Outcome (diabetes diagnosis)
- **Total Samples:** 768

**Data Split:**
- Training: 70% (529 samples)
- Validation: 15% (125 samples)
- Testing: 15% (114 samples)

**How to Run:**
1. Ensure `datasets/diabetes.csv` is available
2. Update the notebook path: `data_path = '../datasets/diabetes.csv'`
3. Run all cells in the notebook
4. Evaluate regression performance metrics

---

### 4. C++ Programs
Various C++ implementations including:
- `1.cpp` - Main assignment implementation
- `another.cpp` - Additional exercises
- `prac.cpp` - Practice problems
- `test.cpp` - Testing implementations
- `text.cpp` - Text processing utilities

**Compilation:**
```bash
g++ -o output filename.cpp
./output
```

---

## 🛠️ Prerequisites

### For Jupyter Notebooks:
```bash
pip install jupyter numpy pandas matplotlib scikit-learn
```

### For C++ Programs:
- GCC/G++ compiler
- C++11 or later

### For Testing Documentation:
```bash
pip install pytest selenium
```

## 🚀 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ai-tanzil811/Assignment.git
   cd Assignment
   ```

2. **Set up Python environment:**
   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows: venv\Scripts\activate
   pip install -r requirements.txt
   ```

3. **Launch Jupyter Notebook:**
   ```bash
   jupyter notebook
   ```

4. **Navigate to the `code/` folder and open desired notebook**

## 📖 Documentation

The `docs/` folder contains study guides and templates for:
- **Automated Testing:** Pytest basics and advanced patterns
- **Selenium WebDriver:** Browser automation and Page Object Model
- **Logging:** Python logging configuration and best practices

### Available Documents:
- `exam_basic_templates.md` - Quick reference for testing basics
- `exam_advanced_templates.md` - Advanced testing patterns
- `selenium_pytest_cheatsheet.md` - Selenium commands and patterns
- `test_practice.py` - Practical testing examples

## 📊 Datasets

### Iris Dataset
Classic machine learning dataset for classification tasks.
- **Source:** UCI Machine Learning Repository
- **Use Case:** Multi-class classification

### Diabetes Dataset
Medical dataset for regression and classification tasks.
- **Source:** National Institute of Diabetes and Digestive and Kidney Diseases
- **Use Case:** Binary classification / Regression

### Graph Data (1.txt, 2.txt)
Custom graph data for pathfinding algorithms.
- **Format:** Node coordinates and edge connections
- **Use Case:** A* algorithm implementation

## 🤝 Contributing

This is an academic repository. If you find issues or have suggestions:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## 📝 Notes

- **Data Paths:** After reorganization, update file paths in notebooks to reference `../datasets/`
- **Compiled Files:** `.exe` files are not tracked in version control
- **Random Seed:** Notebooks use `random.seed(100)` for reproducibility

## 📧 Contact
**Email:** atanzil223028@bscse.uiu.ac.bd
**Student ID:** 012230028  
**Repository:** [ai-tanzil811/Assignment](https://github.com/ai-tanzil811/Assignment)

## 📄 License

This repository is for educational purposes.

---

**Last Updated:** January 2026
