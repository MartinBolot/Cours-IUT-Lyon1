import React, { Component } from 'react';
import '../App.css';
import LeftSide from "./LeftSide/LeftSide";
import Robot from "./Robot/Robot";
import robot from "../sources/robot";

class Main extends Component {
  render() {
    return (
      <div>
        <h1>Welcome to robot shop</h1>
        <LeftSide>
          <Robot robot={robot}/>
        </LeftSide>
      </div>
    );
  }
}

export default Main;
