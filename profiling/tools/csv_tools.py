import csv

def write_csv(csv_file_name, results):
    with open(csv_file_name, 'w') as csv_file:
        csv_writer = csv.writer(csv_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)

        for result in results:
            csv_writer.writerow(result)

def rows_to_columns(matrix):
    return [list(x) for x in zip(*matrix)]
