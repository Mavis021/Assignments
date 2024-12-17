import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import chisquare

# Constants
num_samples = 256  
a = 29
b = 37  
p = 256  
num_bins = 8  
r = np.zeros(num_samples)  
r[0] = 17  # Seed value

# Generate random numbers using Linear Congruential Generator (LCG)
for i in range(1, num_samples):
    r[i] = (r[i - 1] * a + b) % p

# Compute frequency counts for bins
bin_edges = np.linspace(0, p, num_bins + 1)  # Bin edges
bin_counts, _ = np.histogram(r, bins=bin_edges)  # Count numbers in each bin

# Expected frequency for uniform distribution
expected_frequency = num_samples / num_bins

# Perform Chi-square test
chi2_statistic, p_value = chisquare(bin_counts, f_exp=[expected_frequency] * num_bins)

# Display results
print("Generated Random Numbers:")
print(r)
print("\nBin Counts:", bin_counts)
print(f"Chi-square Statistic: {chi2_statistic:.2f}")
print(f"P-value: {p_value:.4f}")
if p_value > 0.05:
    print("Result: The distribution is likely uniform (fail to reject null hypothesis).")
else:
    print("Result: The distribution is not uniform (reject null hypothesis).")

# Plot the random numbers and bin frequencies
plt.figure(figsize=(10, 5))

# Plot random numbers
plt.subplot(1, 2, 1)
plt.plot(r, marker="o", linestyle="--", color="b")
plt.title("Generated Random Numbers")
plt.xlabel("Index")
plt.ylabel("Random Number")

# Plot bin counts
plt.subplot(1, 2, 2)
plt.bar(range(num_bins), bin_counts, color="orange", edgecolor="black")
plt.title("Bin Frequencies")
plt.xlabel("Bins")
plt.ylabel("Frequency")
plt.xticks(range(num_bins), labels=[f"{int(bin_edges[i])}-{int(bin_edges[i+1]-1)}" for i in range(num_bins)], rotation=45)

plt.tight_layout()
plt.savefig("random_number_experiment.png")
plt.show()
