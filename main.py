# from tabulate import tabulate
                 
                
def solve():
    
  

    def function(s):
        print([["a","a","b"]])




    # tests
    tests = [
        ["aab"],
        ["a"]
            ]

    outputs = [ [["a","a","b"],["aa","b"]],[["a"]]]










# Runner
    for test, expected in zip(tests,outputs):
        got = function(*test)
        # print(f"got: {got}")
        # print(f"expected: {expected}")
        # if got == expected:
        #     print("🔥"* 20)
        # else:
        #     print("♻️  " * 13)
   




def printTable(table):
  print(tabulate(table, tablefmt="rounded_grid"))

   
def main():
    solve()


if __name__ == '__main__':
    main()

