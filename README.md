# Machine Learning Algorithms Collection

**Student Name:** Ashraful Islam Tanzil  
**ID:** 0112230028  
**Date:** 2026

---

## Overview

A comprehensive collection of machine learning algorithms implemented in Jupyter Notebooks with real datasets and clean, simple code.

## Project Structure

```
0112230028/
├── environment/
│   ├── kaggle_setup.ipynb
│   └── requirements.txt
├── data_overview/
│   └── dataset_overview.ipynb
├── clustering/
│   ├── kmeans.ipynb
│   ├── modified_kmeans.ipynb
│   ├── hierarchical_clustering.ipynb
│   └── fuzzy_cmeans.ipynb
├── density_based_models/
│   ├── dbscan.ipynb
│   └── hdbscan.ipynb
├── semi_supervised_learning/
│   └── self_training.ipynb
├── ensemble_learning/
│   ├── random_forest_classifier.ipynb
│   ├── random_forest_regressor.ipynb
│   ├── xgboost.ipynb
│   ├── adaboost.ipynb
│   └── catboost.ipynb
├── neural_networks/
│   ├── mlp.ipynb
│   └── grnn.ipynb
├── sequence_models/
│   ├── rnn.ipynb
│   └── hmm.ipynb
├── svm_models/
│   └── svm.ipynb
├── self_organizing_maps/
│   └── som.ipynb
├── llm_analysis/
│   └── llm_text_analysis.ipynb
├── image_based_models/
│   ├── cnn_intro.ipynb
│   └── image_clustering.ipynb
├── datasets/
└── README.md
```

## Algorithms Implemented

### Clustering (4 algorithms)
- **K-Means**: Standard clustering algorithm
- **Modified K-Means++**: Optimized initialization method
- **Hierarchical Clustering**: Agglomerative approach with dendrograms
- **Fuzzy C-Means**: Soft clustering with membership degrees

### Density-Based Models (2 algorithms)
- **DBSCAN**: Density-based spatial clustering
- **HDBSCAN**: Hierarchical density-based clustering

### Semi-Supervised Learning (1 algorithm)
- **Self-Training**: Pseudo-labeling approach

### Ensemble Learning (5 algorithms)
- **Random Forest (Classifier)**: Multiple decision trees
- **Random Forest (Regressor)**: Regression variant
- **XGBoost**: Extreme gradient boosting
- **AdaBoost**: Adaptive boosting
- **CatBoost**: Categorical feature optimization

### Neural Networks (2 algorithms)
- **MLP**: Multilayer perceptron for classification
- **GRNN**: General regression neural network

### Sequence Models (2 algorithms)
- **RNN**: LSTM-based time series prediction
- **HMM**: Hidden Markov models for sequential data

### SVM & Maps (2 algorithms)
- **SVM**: Support vector machine for classification
- **SOM**: Self-organizing maps for unsupervised learning

### NLP & Vision (3 algorithms)
- **LLM**: Transformer-based sentiment analysis
- **CNN**: Convolutional neural networks
- **Image Clustering**: Feature-based clustering with pre-trained models

## Datasets Used

| Dataset | Size | Task | Location |
|---------|------|------|----------|
| Student Lifestyle | 100K rows | Clustering | `dataset/student_lifestyle_100k.csv` |
| Wholesale Customers | 440 rows | Clustering | `dataset/CLUSTERING ALGORITHMS/` |
| City Lifestyle | - | Regression | `dataset/DENSITY-BASED LEARNING/` |
| Breast Cancer | - | Classification | `dataset/SEMI_SUPERVISED_LEARNING/` |
| Adult Income | - | Classification | `dataset/ENSEMBLE_LEARNING/` |
| MNIST | 70K images | Vision | `dataset/MLP/` |
| Air Passengers | 144 records | Time Series | `dataset/RNN/` |

## Getting Started

### 1. Install Dependencies
```bash
cd environment
pip install -r requirements.txt
```

### 2. Run Notebooks
- Start with `data_overview/dataset_overview.ipynb`
- Follow algorithm folders for specific implementations
- Each notebook is independent and self-contained

### 3. Data Preparation
Ensure datasets are in the `dataset/` folder with correct paths as referenced in notebooks.

## Features

- ✅ Clean, comment-free code
- ✅ Markdown titles only (no descriptions)
- ✅ Simple, essential plots only
- ✅ Real-world datasets
- ✅ Metrics and evaluation included
- ✅ Independent notebooks per algorithm
- ✅ Professional organization

## Requirements

- Python 3.9+
- scikit-learn
- TensorFlow/Keras
- XGBoost, CatBoost
- Scikit-Fuzzy, HDBSCAN
- Transformers (HuggingFace)
- Standard libraries (NumPy, Pandas, Matplotlib, Seaborn)

## Running Instructions

Each notebook can be executed independently:
1. Open notebook in Jupyter
2. Run cells sequentially
3. Plots display automatically
4. Results printed to output

## Notes

- All code is clean without comments
- Markdown headers only (no descriptions)
- Plotting is minimal and essential
- Student name and ID included in each notebook header
- Proper data paths configured for relative imports

---

**Last Updated:** January 2026
