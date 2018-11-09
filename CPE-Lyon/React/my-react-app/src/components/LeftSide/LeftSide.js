import React, { Component } from 'react';
import Robot from "../Robot/Robot";

class LeftSide extends Component {
  constructor(props) {
    super(props);
    this.state = {
      robots: this.props.robots,
    }
    this.handleRobotClick = this.handleRobotClick.bind(this);
  }

  handleRobotClick(id) {
    this.props.handleLeftSideClick(id);
  }

  render() {
      return this.state.robots.map((robot, index) => {
          return (
            <Robot
              key={index}
              robot={robot}
              selected={this.props.selectedRobotId === robot.id}
              handleRobotClick={this.handleRobotClick}
            />
          );
      });
  }
}

export default LeftSide;
