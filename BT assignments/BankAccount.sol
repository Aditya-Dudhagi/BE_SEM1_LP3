// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{
    mapping(address => uint256) private balances;

    function deposit() public payable {
        require(msg.value > 0, "Deposit must be greater than 0");
        balances[msg.sender] += msg.value;
    }

    function withdraw(uint256 amount) public {
        require(amount>0, "Amount cannot be 0");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        balances[msg.sender] -= amount;

        (bool success, ) = payable(msg.sender).call{value: amount}("");
        require(success, "Transfer failed");
    }

    function showBalance() public view returns (uint256){
        return balances[msg.sender];
    }
}