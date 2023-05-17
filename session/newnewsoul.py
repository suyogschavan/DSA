import random
import string
import datetime
import pandas as pd

# Set up some parameters for the dataset
start_date = datetime.date(2022, 1, 1)
end_date = datetime.date(2022, 12, 31)
num_transactions = 1000

# Generate some random transaction data
transactions = []
for i in range(num_transactions):
    date = start_date + datetime.timedelta(days=random.randint(0, (end_date - start_date).days))
    amount = round(random.uniform(-1000, 1000), 2)
    description = ''.join(random.choices(string.ascii_letters + string.digits, k=10))
    transactions.append((date, amount, description))

# Create a pandas DataFrame from the transaction data
df = pd.DataFrame(transactions, columns=['Date', 'Amount', 'Description'])

# Add a running balance column to the DataFrame
df['Balance'] = df['Amount'].cumsum()

# Save the DataFrame to an XLSX file
filename = 'bank_statement.xlsx'
df.to_excel(filename, index=False)

print(f"Generated bank statement dataset saved to {filename}")
