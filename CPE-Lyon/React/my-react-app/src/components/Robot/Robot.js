import React, { Component } from 'react';
import { connect } from 'react-redux';
import Label from "./container/Label";
import Visual from "./container/Visual";
import { setSelectedRobot } from "./../../actions"

class Robot extends Component {
  constructor(props) {
    super(props);
    this.handleClick = this.handleClick.bind(this);
  }

  handleClick() {
    this.props.dispatch(setSelectedRobot(this.props.robot))
  }

  render() {
    const primaryClass = (
      "panel panel-default " +
      (this.props.selected ? "panel-primary" : "")
    );
    return (
      <div className={primaryClass}>
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
            id={this.props.robot.id}
            type={this.props.robot.visual_type}
            src={this.props.robot.visual_src}
          />
          </div>
      </div>

    );
  }
}

export default connect()(Robot);
