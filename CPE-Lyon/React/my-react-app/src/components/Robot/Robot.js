import React, { Component } from 'react';
import Label from "./container/Label";
import Visual from "./container/Visual";

class Robot extends Component {
  constructor(props) {
    super(props);
    this.handleClick = this.handleClick.bind(this);
  }

  handleClick(e) {
    this.props.handleRobotClick(this.props.robot.id);
  }

  render() {
    const primaryClass = this.props.selected ? "panel-primary" : "";
    return (
      <div className={"panel panel-default" + " " + primaryClass}>
        <div className="panel-heading">
          <h3
            className="panel-title"
            onClick={this.handleClick}
          >
            Robot {this.props.robot.id} description
          </h3>
        </div>
        <div className="panel-body">
          <Label label={this.props.robot.label}/>
          <Visual
            robotId={this.props.robot.id}
            type={this.props.robot.visual_type}
            source={this.props.robot.visual_src}/>
          </div>
      </div>

    );
  }
}

export default Robot;
