# Bitcoin Exchange Program Documentation
<!-- mtoc-start -->

* [Overview](#overview)
* [Program Structure](#program-structure)
  * [Class Structure](#class-structure)
* [Functionality](#functionality)
  * [Data Storage](#data-storage)
  * [Data Processing](#data-processing)
    * [Reading Exchange Rates](#reading-exchange-rates)
    * [Processing User Input](#processing-user-input)
  * [Input Validation](#input-validation)
  * [Exchange Rate Lookup](#exchange-rate-lookup)
* [Error Handling](#error-handling)
* [Usage](#usage)
* [Technical Implementation Details](#technical-implementation-details)
  * [Date Parsing and Comparison](#date-parsing-and-comparison)
  * [String Processing](#string-processing)
  * [Date Conversion](#date-conversion)

<!-- mtoc-end -->
## Overview

This program implements a Bitcoin exchange rate calculator that processes historical Bitcoin price data and calculates the value of Bitcoin holdings on specific dates. The application reads exchange rates from a CSV file and processes user input to calculate Bitcoin values based on these rates.

## Program Structure

The program consists of three main files:
- `BitcoinExchange.hpp`: Header file containing class declarations
- `BitcoinExchange.cpp`: Implementation file with method definitions
- `main.cpp`: Entry point for the application

### Class Structure

The `BitcoinExchange` class is the core component of the program, responsible for:
1. Reading and storing Bitcoin exchange rate data
2. Processing user input data
3. Calculating Bitcoin values based on exchange rates
4. Validating input formats and values

## Functionality

### Data Storage

The program uses a `std::map` container to store Bitcoin exchange rates, with dates as keys and exchange rates as values. This provides efficient lookup by date with automatic sorting.

### Data Processing

#### Reading Exchange Rates
The `readData()` method reads Bitcoin exchange rates from a CSV file with the format:
```
date,exchange_rate
2022-03-01,44000.5
```

#### Processing User Input
The `processData()` method processes a user-provided file with the format:
```
date | value
2022-03-01 | 10
```

### Input Validation

The program implements comprehensive input validation:

1. **Date Validation** (`isDateValid`): 
   - Ensures dates follow the YYYY-MM-DD format
   - Validates that dates are legitimate calendar dates

2. **Value Validation** (`isValueValid`, `isPositiveVal`, `isWithinRange`):
   - Checks that values are properly formatted numbers
   - Ensures values are positive
   - Verifies values are within acceptable range (≤ 1000)

3. **Input Format Validation** (`isInputValid`):
   - Validates the overall format of input lines
   - Checks for proper delimiter usage

### Exchange Rate Lookup

When calculating Bitcoin values, the program:
1. Attempts to find an exact date match in the database
2. If no exact match exists, finds the nearest available date using `getNearestDate()`

## Error Handling

The program uses exception handling to manage various error conditions:
- File opening errors
- Invalid file formats
- Input validation failures

Custom exception classes provide specific error messages for different error types.

## Usage

The program is executed from the command line with the following syntax:
```bash
./BitcoinExchange 
```

Where `` is a file containing Bitcoin values to be calculated, and the program expects a `data.csv` file in the current directory containing historical exchange rates.

## Technical Implementation Details

### Date Parsing and Comparison

The program uses the `strptime()` function to parse date strings and validate them against the calendar. The `isSameDate()` method ensures date components match after normalization.

### String Processing

Several helper methods handle string manipulation:
- `removeSpace()`: Removes all whitespace from a string
- `trimSpaces()`: Removes leading and trailing spaces

### Date Conversion

The `toLongDate()` method converts date strings to numeric values for efficient comparison when finding the nearest date in the database.

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/02afd7c8-64b7-4075-8569-c7eda8d2a3fd/main.cpp
[2] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/12daffec-d355-4545-81f7-899289fad9e1/BitcoinExchange.cpp
[3] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/26d2d2b2-5037-4009-8223-5bf15c37acd4/BitcoinExchange.hpp
[4] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/02afd7c8-64b7-4075-8569-c7eda8d2a3fd/main.cpp
[5] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/12daffec-d355-4545-81f7-899289fad9e1/BitcoinExchange.cpp
