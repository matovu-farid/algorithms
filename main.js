

function add(num1, num2) {
	let remainder = 0;
	let total = 0;
	let [numOne, numTwo]=  [Number(num1), Number(num2)]
	while(numOne !== 0 && numTwo !== 0){
		total *= 10
		let val1 = paseInt(numOne / 10) 
		let val2 = parseInt(numTwo / 10)
		total += (val1 + val2 + remainder) % 10

	}
	return total.toString()
}
const testResults = [add("123", "321"),
add("11", "99")]

for (let testResult of testResults) {
	console.log(testResult)
}
