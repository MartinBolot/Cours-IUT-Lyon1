import React, { Component } from 'react';
import Robot from "../Robot/Robot";

class LeftSide extends Component {
  constructor(props) {
    super(props);
    this.state = {
      robots: this.props.robots,
    }
  }

  render() {
      return this.state.robots.map((robot, index) => {
          return (
            <Robot
              key={index}
              robot={robot}
              selected={this.props.selectedRobotId === robot.id}
            />
          );
      });
  }
}

export default LeftSide;
